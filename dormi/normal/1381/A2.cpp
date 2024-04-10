#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
bool a[MAXN],b[MAXN];
int maxblocksize;

struct node {
    vector<int> arr;
    int prefix, lazy, sum, prema, sufma, madif;
    bool reverse;

    node(int a = 0) {
        prefix = a;
        lazy = INT_MIN;
        sum = 0;
        prema = 0;
        sufma = 0;
        madif = 0;
        reverse=false;
    }
    void swape(node &x){
        swap(prefix,x.prefix);
        swap(lazy,x.lazy);
        swap(sum,x.sum);
        swap(prema,x.prema);
        swap(sufma,x.sufma);
        swap(madif,x.madif);
        swap(reverse,x.reverse);
        arr.swap(x.arr);
    }
    const bool operator<(const int& rhs) const {
        return prefix<rhs;
    }
};
vector<node> sqr;

void reversenode(int st, int en){
    while(st<en){
        sqr[st++].swape(sqr[en--]);
    }
}

void resolve(int ind) {
    if (sqr[ind].lazy != INT_MIN)sqr[ind].arr.assign(sqr[ind].arr.size(), sqr[ind].lazy);
    sqr[ind].lazy = INT_MIN;
}

void resolvere(int ind) {
    if (sqr[ind].reverse) {
        reverse(sqr[ind].arr.begin(), sqr[ind].arr.end());
        swap(sqr[ind].sufma, sqr[ind].prema);
    }
    sqr[ind].reverse = false;
}

void recalc(int ind) {
    resolve(ind);
    resolvere(ind);
    sqr[ind].sum = sqr[ind].arr[0];
    sqr[ind].prema = sqr[ind].arr[0];
    int mi = min(0,sqr[ind].sum);
    sqr[ind].madif = sqr[ind].arr[0];
    sqr[ind].sufma = INT_MIN;
    for (int i = 1; i < sqr[ind].arr.size(); i++) {
        sqr[ind].sum += sqr[ind].arr[i];
        sqr[ind].madif = max(sqr[ind].madif, sqr[ind].sum - mi);
        sqr[ind].prema = max(sqr[ind].prema, sqr[ind].sum);
        mi = min(mi, sqr[ind].sum);
    }
    int sum = 0;
    for (int i = sqr[ind].arr.size() - 1; i >= 0; i--) {
        sum += sqr[ind].arr[i];
        sqr[ind].sufma = max(sqr[ind].sufma, sum);
    }
}

void pre(int ind) {
    for (int i = ind + 1; i < sqr.size(); i++) {
        sqr[i].prefix = sqr[i - 1].prefix + sqr[i - 1].arr.size();
    }
}

void rebuild(){
    vector<node> temp;
    int loc=0;
    int index=0;
    temp.push_back(node());
    for(int i=0;i<sqr.size();i++){
        if(sqr[i].arr.size()) {
            resolve(i);
            resolvere(i);
            for (int j:sqr[i].arr) {
                if (loc == maxblocksize) {
                    loc = 0;
                    index += 1;
                    temp.push_back(node());
                }
                temp[index].arr.push_back(j);
                loc += 1;
            }
        }
    }
    sqr=temp;
    for(int i=0;i<=index;i++){
        recalc(i);
    }
    pre(0);
}
vector<int> inser;
void insert(int loc) {
    if (sqr.size() == 0) {
        sqr.push_back(node());
    }
    int ind = (lower_bound(sqr.begin(), sqr.end(), loc + 1) - sqr.begin()) - 1;
    resolve(ind);
    resolvere(ind);
    loc -= sqr[ind].prefix;
    sqr[ind].arr.insert(sqr[ind].arr.begin() + loc, inser.begin(),inser.end());
    while (sqr[ind].arr.size() >= maxblocksize * 2) {
        sqr.insert(sqr.begin() + ind + 1, node());
        for (int i = (int)sqr[ind].arr.size()-maxblocksize; i <sqr[ind].arr.size() ; i++)sqr[ind + 1].arr.push_back(sqr[ind].arr[i]);
        sqr[ind].arr.resize((int)sqr[ind].arr.size()-maxblocksize);
        recalc(ind + 1);
    }
    recalc(ind);
    pre(ind);
    inser.clear();
}

void massdel(int l, int r) {
    if (sqr.size() == 0) {
        return;
    }
    int le = (lower_bound(sqr.begin(), sqr.end(), l) - sqr.begin()) - 1;
    int ri = (lower_bound(sqr.begin(), sqr.end(), r) - sqr.begin()) - 1;
    l -= 1;
    r -= 1;
    if (le == ri) {
        resolvere(le);
        sqr[le].arr.erase(sqr[le].arr.begin()+(l - sqr[le].prefix),sqr[le].arr.begin()+(r - sqr[le].prefix+1));
        if (sqr[le].arr.size() == 0) {
            sqr.erase(sqr.begin() + le);
        } else {
            recalc(le);
        }
    } else {
        if (ri > le + 1) {
            sqr.erase(sqr.begin() + le + 1, sqr.begin() + ri);
        }
        bool del = false;
        if (l == sqr[le].prefix) {
            sqr.erase(sqr.begin() + le);
            del = true;
        } else {
            resolvere(le);
            sqr[le].arr.erase(sqr[le].arr.begin()+(l - sqr[le].prefix), sqr[le].arr.end());
            recalc(le);
        }
        if (del)ri = le;
        else ri = le + 1;
        if (r == sqr[ri].prefix + sqr[ri].arr.size()-1) {
            sqr.erase(sqr.begin() + ri);
        } else {
            resolvere(ri);
            sqr[ri].arr.erase(sqr[ri].arr.begin(),sqr[ri].arr.begin()+(r - sqr[ri].prefix+1));
            recalc(ri);
        }
    }
    if (le < sqr.size()) {
        if (le > 0) {
            sqr[le].prefix = sqr[le - 1].prefix + sqr[le - 1].arr.size();
        } else {
            sqr[le].prefix = 0;
        }
    }
    pre(le);
}

void rangeupdate(int a, int l, int r) {
    if (sqr.size() == 0) {
        return;
    }
    int le = (lower_bound(sqr.begin(), sqr.end(), l) - sqr.begin()) - 1;
    int ri = (lower_bound(sqr.begin(), sqr.end(), r) - sqr.begin()) - 1;
    l -= 1;
    r -= 1;
    if (le == ri) {
        resolve(le);
        resolvere(le);
        for (int i = l - sqr[le].prefix; i <= r - sqr[le].prefix; i++) {
            sqr[le].arr[i] = a;
        }
        recalc(le);
    } else {
        if (ri > le + 1) {
            for (int i = le + 1; i < ri; i++) {
                sqr[i].lazy = a;
                sqr[i].sum = a * sqr[i].arr.size();
                if (a < 0) {
                    sqr[i].prema = a;
                    sqr[i].sufma = a;
                    sqr[i].madif = a;
                } else {
                    sqr[i].prema = a * sqr[i].arr.size();
                    sqr[i].sufma = a * sqr[i].arr.size();
                    sqr[i].madif = sqr[i].sum;
                }
            }
        }
        if (l == sqr[le].prefix) {
            sqr[le].lazy = a;
            sqr[le].sum = a * sqr[le].arr.size();
            if (a < 0) {
                sqr[le].prema = a;
                sqr[le].sufma = a;
                sqr[le].madif = a;
            } else {
                sqr[le].prema = a * sqr[le].arr.size();
                sqr[le].sufma = a * sqr[le].arr.size();
                sqr[le].madif = sqr[le].sum;
            }
        } else {
            resolve(le);
            resolvere(le);
            for (int i = l - sqr[le].prefix; i < sqr[le].arr.size(); i++) {
                sqr[le].arr[i] = a;
            }
            recalc(le);
        }
        if (r == sqr[ri].prefix + sqr[ri].arr.size()) {
            sqr[ri].lazy = a;
            sqr[ri].sum = a * sqr[ri].arr.size();
            if (a < 0) {
                sqr[ri].prema = a;
                sqr[ri].sufma = a;
                sqr[ri].madif = a;
            } else {
                sqr[ri].prema = a * sqr[ri].arr.size();
                sqr[ri].sufma = a * sqr[ri].arr.size();
                sqr[ri].madif = sqr[ri].sum;
            }
        } else {
            resolve(ri);
            resolvere(ri);
            for (int i = 0; i <= r - sqr[ri].prefix; i++) {
                sqr[ri].arr[i] = a;
            }
            recalc(ri);
        }
    }
}

void rever(int l, int r) {
    if (sqr.size() == 0) {
        return;
    }
    int le = (lower_bound(sqr.begin(), sqr.end(), l) - sqr.begin()) - 1;
    int ri = (lower_bound(sqr.begin(), sqr.end(), r) - sqr.begin()) - 1;
    l -= 1;
    r -= 1;
    if (le == ri) {
        resolvere(le);
        reverse(sqr[le].arr.begin()+(l - sqr[le].prefix), sqr[le].arr.begin()+(r - sqr[le].prefix + 1));
        recalc(le);
    } else {
        if (ri > le + 1) {
            reversenode(le + 1,ri-1);
            for (int i = le + 1; i < ri; i++) {
                sqr[i].reverse = !sqr[i].reverse;
            }
        }
        resolve(ri);
        resolvere(ri);
        resolve(le);
        resolvere(le);
        l -= sqr[le].prefix;
        r -= sqr[ri].prefix;
        int te = min((int) sqr[le].arr.size() - l - 1, r);
        for (int i = 0; i <= te; i++) {
            swap(sqr[le].arr[i + l], sqr[ri].arr[r - i]);
        }
        if (te + 1 <= sqr[le].arr.size() - l - 1) {
            reverse(sqr[le].arr.begin()+(te + 1 + l), sqr[le].arr.end());
            sqr[ri].arr.insert(sqr[ri].arr.begin(), sqr[le].arr.begin()+(te + 1 + l), sqr[le].arr.end());
            sqr[le].arr.resize(te + l + 1);
            if (sqr[ri].arr.size() >= maxblocksize * 2) {
                sqr.insert(sqr.begin() + ri + 1, node());
                for (int i = maxblocksize; i <sqr[ri].arr.size(); i++)sqr[ri + 1].arr.push_back(sqr[ri].arr[i]);
                sqr[ri].arr.resize(maxblocksize);
                recalc(ri + 1);
                if (sqr[ri + 1].arr.size() >= maxblocksize * 2) {
                    sqr.insert(sqr.begin() + ri + 2, node());
                    for (int i = maxblocksize; i <sqr[ri+1].arr.size(); i++)sqr[ri + 2].arr.push_back(sqr[ri + 1].arr[i]);
                    sqr[ri + 1].arr.resize(maxblocksize);
                    recalc(ri + 2);
                    recalc(ri + 1);
                }
            }
        } else if (te + 1 <= r) {
            //printf("%d %dhii\n",te,r);
            reverse(sqr[ri].arr.begin(),sqr[ri].arr.begin()+(r - te));
            sqr[le].arr.insert(sqr[le].arr.end(), sqr[ri].arr.begin(), sqr[ri].arr.begin()+(r - te));
            sqr[ri].arr.erase(sqr[ri].arr.begin(), sqr[ri].arr.begin()+(r - te));
            if (sqr[le].arr.size() >= maxblocksize * 2) {
                sqr.insert(sqr.begin() + le + 1, node());
                ri+=1;
                for (int i = maxblocksize; i <sqr[le].arr.size(); i++)sqr[le + 1].arr.push_back(sqr[le].arr[i]);
                sqr[le].arr.resize(maxblocksize);
                recalc(le + 1);
                if (sqr[le + 1].arr.size() >= maxblocksize * 2) {
                    sqr.insert(sqr.begin() + le + 2, node());
                    ri+=1;
                    for (int i = maxblocksize; i <sqr[le+1].arr.size(); i++)sqr[le + 2].arr.push_back(sqr[le + 1].arr[i]);
                    sqr[le + 1].arr.resize(maxblocksize);
                    recalc(le + 2);
                    recalc(le + 1);
                }
            }
        }
        recalc(ri);
        recalc(le);
        pre(le);
    }
}

int getsum(int l, int r) {
    if (sqr.size() == 0) {
        return 0;
    }
    int le = (lower_bound(sqr.begin(), sqr.end(), l) - sqr.begin()) - 1;
    int ri = (lower_bound(sqr.begin(), sqr.end(), r) - sqr.begin()) - 1;
    l -= 1;
    r -= 1;
    int count = 0;
    if (le == ri) {
        resolve(le);
        resolvere(le);
        for (int i = l - sqr[le].prefix; i <= r - sqr[le].prefix; i++) {
            count += sqr[le].arr[i];
        }
    } else {
        for (int i = le + 1; i < ri; i++) {
            count += sqr[i].sum;
        }
        if (l == sqr[le].prefix) {
            count += sqr[le].sum;
        } else {
            resolve(le);
            resolvere(le);
            for (int i = l - sqr[le].prefix; i < sqr[le].arr.size(); i++) {
                count += sqr[le].arr[i];
            }
        }
        if (r == sqr[ri].prefix + sqr[ri].arr.size()) {
            count += sqr[ri].sum;
        } else {
            resolve(ri);
            resolvere(ri);
            for (int i = 0; i <= r - sqr[ri].prefix; i++) {
                count += sqr[ri].arr[i];
            }
        }
    }
    return count;
}

int maxsum() {
    int ma = INT_MIN;
    int endmax = 0;
    for (int i = 0; i < sqr.size(); i++) {
        ma = max(ma, max(sqr[i].madif, (sqr[i].reverse ? sqr[i].sufma : sqr[i].prema) + endmax));
        endmax = max(endmax + sqr[i].sum, (sqr[i].reverse ? sqr[i].prema : sqr[i].sufma));
    }
    return ma;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        sqr=vector<node>();
        int n;
        cin>>n;
        char in;
        int loc=0;
        int index=0;
        maxblocksize=sqrt(n);
        sqr.push_back(node());
        for(int i=0;i<n;i++){
            cin>>in;
            a[i]=(in=='1');
            if (loc == maxblocksize) {
                loc = 0;
                index += 1;
                sqr.push_back(node());
            }
            sqr[index].arr.push_back(a[i]);
            loc += 1;
        }
        for(int i=0;i<=index;i++){
            recalc(i);
        }
        pre(0);
        for(int i=0;i<n;i++){
            cin>>in;
            b[i]=(in=='1');
        }
        vector<int> moves;
        int flips=0;
        for(int i=n-1;i>=0;i--){
            int x=getsum(i+1,i+1);
            if(flips%2)x=!x;
            if(x!=b[i]){
                int xte=getsum(1,1);
                if(flips%2)xte=!xte;
                if(xte!=x){
                    moves.push_back(1);
                    rangeupdate((xte?-1:1),1,1);
                }
                moves.push_back(i+1);
                flips++;
                rever(1,i+1);
            }
        }
        printf("%d ",sz(moves));
        for(auto x:moves)printf("%d ",x);
        printf("\n");
    }
    return 0;
}
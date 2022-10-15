#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=201;

int n,dif[N];
string v[N];
map<string,int>mp;
map<string, vector<int> >aux;

struct info {
    string a;
    int cnt;
};

const int L=4*1008000+123;

info sol[L];
int cnt=0;

bool cmp(info x,info y) {
    return x.cnt<y.cnt;
}

string ans[N];
bool ok[N];

bool cmp2(int x,int y) {
    return dif[x]<dif[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    map<string,int>cur;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        int l=v[i].size();
        if(l<=4) {
            mp[v[i]]++;
            aux[v[i]].push_back(i);
            continue;
        }
        cur.clear();
        /// 1
        for(int p1=0;p1<l;p1++) {
            string a;
            a+=v[i][p1];
            mp[a]++;
            aux[a].push_back(i);
            if(cur[a]==0)dif[i]++;cur[a]++;
        }
        /// 2
        for(int p1=0;p1<l;p1++)
            for(int p2=p1+1;p2<l;p2++) {
                string a;
                a+=v[i][p1];
                a+=v[i][p2];
                mp[a]++;
                aux[a].push_back(i);
                if(cur[a]==0)dif[i]++;cur[a]++;
            }
        /// 3
        for(int p1=0;p1<l;p1++)
            for(int p2=p1+1;p2<l;p2++)
                for(int p3=p2+1;p3<l;p3++) {
                    string a;
                    a+=v[i][p1];
                    a+=v[i][p2];
                    a+=v[i][p3];
                    mp[a]++;
                    aux[a].push_back(i);
                    if(cur[a]==0)dif[i]++;cur[a]++;
                }
        /// 4
        for(int p1=0;p1<l;p1++)
            for(int p2=p1+1;p2<l;p2++)
                for(int p3=p2+1;p3<l;p3++)
                    for(int p4=p3+1;p4<l;p4++) {
                        string a;
                        a+=v[i][p1];
                        a+=v[i][p2];
                        a+=v[i][p3];
                        a+=v[i][p4];
                        mp[a]++;
                        aux[a].push_back(i);
                        if(cur[a]==0)dif[i]++;cur[a]++;
                    }
    }
    for(auto x:mp) {
        cnt++;
        sol[cnt].a=x.first;
        sol[cnt].cnt=x.second;
    }
    sort(sol+1,sol+cnt+1,cmp);
    for(int i=1;i<=cnt;i++) {
        sort(aux[sol[i].a].begin(),aux[sol[i].a].end(),cmp2);
        for(auto ind:aux[sol[i].a]) {
            if(ok[ind]==0) {
                ans[ind]=sol[i].a;
                ok[ind]=1;
                break;
            }
        }
    }
    bool is=1;
    for(int i=1;i<=n;i++) {
        if(ok[i]==0) {
            is=0;
            break;
        }
    }
    if(is==1) {
        for(int i=1;i<=n;i++) {
            cout<<ans[i]<<"\n";
        }
    }
    else {
        cout<<"-1\n";
    }
    return 0;
}
/**

**/
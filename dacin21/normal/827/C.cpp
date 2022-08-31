//really fast iterative segment-tree implementation
//uses std::function for subtree-merges and leaf-updates
#include <bits/stdc++.h>
using namespace std;

array<int, 4> idVal = {0, 0, 0 ,0};
struct segTree{
    using T = array<int, 4>;
    vector<T> data;
    int N;
    T combine(T const&a, T const&b){
        return {a[0]+b[0], a[1]+b[1], a[2]+b[2], a[3]+b[3]};
    }
    void leafMod(T &a, T const&b){
        a=b;
    }
    segTree(vector<T> const&base):N(base.size()){
        data.resize(2*N);
        copy(base.begin(), base.end(), data.begin()+N);
        for(int i=N-1;i>=0;--i){
            data[i]=combine(data[i<<1], data[i<<1|1]);
        }
    }
    void update(int pos, T val){
        for(leafMod(data[pos+=N], val);pos>>=1;){
            data[pos]=combine(data[pos<<1], data[pos<<1|1]);
        }
    }
    T query(int l, int r){
        //cerr << "q: " << l << " / " << r << "\n";
        T retL=idVal, retR=idVal;
        for(l+=N, r+=N;l<r;l>>=1, r>>=1){
            if(l&1)retL=combine(retL, data[l++]);
            if(r&1)retR=combine(data[--r], retR);
        }
        //auto e = combine(retL, retR); cerr << "->"; for(int f:e) cerr << f << " "; cerr << "\n";
        return combine(retL, retR);
    }
};

array<char, 4> enco = {'A', 'T', 'G', 'C'};
const int MAS = 11;

array<int, 4> genar(char c){
    switch(c){
        case 'A':
            return {1, 0, 0, 0};
        case 'T':
            return {0, 1, 0, 0};
        case 'G':
            return {0, 0, 1, 0};
        case 'C':
            return {0, 0, 0, 1};
    }
    assert(0);
    return {0, 0, 0 ,0};
}

int scal(array<int, 4> const&a, array<int, 4> const&b){
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
}

using ll = long long;
ll inf = 1e18;
int main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTTT; cin >> TTTT;
    while(TTTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<segTree> > tres(MAS);

    for(int i=1;i<MAS;++i){
        vector<vector<array<int, 4> > > b(i);
        for(int j=0;j<n;++j){
            b[j%i].emplace_back(genar(s[j]));
        }
        for(int j=0;j<i;++j) tres[i].emplace_back(b[j]);
    }
    int q; cin >> q;
    while(q--){
        int x, a, b; cin >> x;
        char c;
        if(x==1){
            cin >> a >> c;
            --a;
            for(int i=1;i<MAS;++i){
                tres[i][a%i].update(a/i, genar(c));
            }
        } else {
            assert(x==2);
            cin >> a >> b >> s;
            --a, --b;
            int j = s.size(), ans=0;
            for(int i=0;i<j;++i){
                //cerr << s[(i-a%j+j)%j] << " ";
                ans+= scal(genar(s[(i-a%j+j)%j]), tres[j][i].query((a-i+j-1)/j, (b-i+j)/j));
            }
            cout << ans << "\n";
        }
    }







    #ifdef LOCAL_RUN
    cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}
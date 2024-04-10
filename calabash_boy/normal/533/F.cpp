#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 2e5+100;
/*
 * char* 1-bas
 * sum[i] = s[i]+s[i-1]*Seed+s[i-2]*Seed^2+...+s[1]*Seed^(i-1)
 */
ULL Seed_Pool[]={19260817,91815541};
ULL Mod_Pool[]={1000000009,4294967291ull};
ULL bas[maxn];

ULL Seed,Mod;
struct Hash_1D{
    ULL sum[maxn];
    void init(char *s ,int n,int seedIndex,int modIndex,char ch){
        static bool first_use = true;
        //cerr<<first_use<<endl;

        if (first_use){
            Seed = Seed_Pool[seedIndex];
            Mod = Mod_Pool[modIndex];
            bas[0]=1;
            for (int i=1;i<=n;i++){
                bas[i] = bas[i-1]*Seed%Mod;
            }
            first_use = false;
        }
        for (int i=1;i<=n;i++){
            // cerr<<s[i]<<" "<<ch<<endl;
            int delta =(s[i] == ch?1:0);
            sum[i] = (sum[i-1]*Seed%Mod+delta)%Mod;
        }
    }

    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}hasher[26],hasher2[26];
char s[maxn],t[maxn];
int used[26];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for (char ch = 'a';ch<='z';ch++){
        hasher[ch - 'a'].init(s,n,1,1,ch);
        hasher2[ch - 'a'].init(t,m,1,1,ch);
    }
    vector<pair<ULL,int>> vect(0);
    for (int i=0;i<26;i++){
        ULL hash_val = hasher2[i].getHash(1,m);
        vect.push_back({hash_val,i});
    }
    sort(vect.begin(),vect.end());
    vector<int >ans(0);
    for (int st = 1;st <= n-m+1;st++){
        vector<pair<ULL,int> > vecs(0);
        memset(used,-1,sizeof used);
        int l = st;
        int r = l + m-1;
        for (int i=0;i<26;i++){
            ULL hash_val = hasher[i].getHash(l,r);
            vecs.push_back({hash_val,i});
        }
        sort(vecs.begin(),vecs.end());
//        cout<<"st: "<<st<<endl;
//        for (int i=0;i<26;i++){
//            cout<<"("<<vect[i].first<<" "<<vect[i].second<<") ";
//        }
//        cout<<endl;
//        for (int i=0;i<26;i++){
//            cout<<"("<<vecs[i].first<<" "<<vecs[i].second<<") ";
//        }cout<<endl;
        bool succ = true;
        for (int i=0;i<26;i++){
            if (vecs[i].first != vect[i].first){
                succ = false;
                break;
            }
            if (vecs[i].first == 0)continue;
            //cout<<2*bas[m]%Mod<<endl;
            int x = vecs[i].second;
            int y = vect[i].second;
            if (used[x]!=-1 && used[x] != y){
                succ = false;
                break;
            }
            if (used[y]!=-1 && used[y] != x){
                succ = false;
                break;
            }
            used[x] = y;
            used[y] = x;
        }
        if (succ)ans.push_back(st);
    }
    printf("%d\n",(int)ans.size());
    for (int x : ans)printf("%d ",x);
    return 0;
}
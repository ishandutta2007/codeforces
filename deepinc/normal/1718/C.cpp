#include<bits/stdc++.h>
using namespace std;
int n,m,a[233333];
vector<int>v;
vector<long long>s[6666];
multiset<long long>S;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int t; cin>>t; while(t--){
        cin>>n>>m;
        int c=0,t=n;
        for(int i=2;i*i<=t;++i)if(t%i==0){
            v.push_back(n/i), s[c++].resize(n/i); 
            while(i>1&&t%i==0)t/=i;
        }
        if(t>1&&t!=n) v.push_back(n/t), s[c++].resize(n/t);
        v.push_back(1), s[c++].resize(1);
        for(int i=0;i<c;++i) for(int j=0; j<v[i]; ++j) s[i][j]=0;
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            for(int j=0;j<c;++j) s[j][i%v[j]]+=a[i];
        }
        for(int i=0;i<c;++i) for(int j=0; j<v[i]; ++j) S.insert(v[i]*s[i][j]);
        printf("%lld\n", *(--S.end()));
        while(m--){
            int x,w; scanf("%d%d",&x,&w); x--;
            for(int j=0;j<c;++j) S.erase(S.find(v[j]*s[j][x%v[j]])),s[j][x%v[j]]-=a[x];
            a[x]=w;
            for(int j=0;j<c;++j) s[j][x%v[j]]+=a[x],S.insert(v[j]*s[j][x%v[j]]);
            printf("%lld\n", *(--S.end()));
        }
        v.clear(); S.clear();
    }
}
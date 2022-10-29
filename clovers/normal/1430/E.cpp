#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N]; int n;
vector<int> v1[30],v2[30];
namespace BIT{
    int a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int add){
        for(int i=x;i<=n;i+=lowbit(i)) a[i]+=add;
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
}

int from[N];
int main(){
    scanf("%d",&n); scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        int c=s[i]-'a';
        v1[c].push_back(i);
        v2[c].push_back(n-i+1);
    }
    for(int i=0;i<26;i++)
        sort(v1[i].begin(),v1[i].end()),
        sort(v2[i].begin(),v2[i].end());
    long long ans=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<(int)v1[i].size();j++){
            int pos1=v1[i][j],pos2=v2[i][j];
            from[pos2]=pos1;
        }
    }
    for(int i=1;i<=n;i++){
        int nowpos=from[i]+BIT::query(from[i]);
        //cout<<i<<" "<<from[i]<<" "<<nowpos<<endl;
        if(nowpos==i) continue;
        ans+=nowpos-i;
        BIT::update(1,1); BIT::update(from[i],-1);
    }
    cout<<ans<<endl;
    return 0;
}
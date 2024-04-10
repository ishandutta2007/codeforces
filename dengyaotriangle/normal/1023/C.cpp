#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

char s[maxn];
int p[maxn];
int n,k;
stack<int> pt;
pair<int,int> x[maxn];
int m;
char t[maxn];

int main(){
    cin>>n>>k;
    cin>>(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='(')pt.push(i);
        else{
            int u=pt.top();pt.pop();
            x[++m]=make_pair(u,i);
        }
    }
    for(int i=1;i<=k/2;i++){
        t[x[i].first]='(';
        t[x[i].second]=')';
    }
    for(int i=1;i<=n;i++){
        if(t[i])cout<<t[i];
    }
    return 0;
}
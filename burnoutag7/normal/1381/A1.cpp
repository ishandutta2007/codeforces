#include<bits/stdc++.h>
using namespace std;

int n;
char a[100005];
char b[100005];
bool rev,inv;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>a+1;
        vector<int> rnk,op;
        for(int i=1;i<=n+1>>1;i++){
            rnk.emplace_back(i);
            if(i!=n-i+1)rnk.emplace_back(n-i+1);
        }
        cin>>b+1;
        for(int i=n,j=0;i>=1;i--,j++){
            int cur=(a[rnk[j]]-'0')^(j&1)^1,dsr=b[i]-'0';
            if(cur!=dsr)op.emplace_back(1);
            op.emplace_back(i);
        }
        cout<<op.size()<<' ';
        for(int &x:op){
            cout<<x<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
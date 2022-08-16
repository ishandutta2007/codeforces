#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        int k=x-y;
        if(k<0)k*=-1;
        int m=k/d;
        if(k%d){
            k=(x-2+d)/d+(y-1)/d;
            if((y-1)%d)k=-1;
            m=(n-x+d-1)/d+(n-y)/d;
            if((n-y)%d)m=-1;
            if(k==-1&&m==-1){
            cout<<-1<<"\n";continue;}
            else if(k==-1);
            else if(m==-1)m=k;
            else if(m>k)m=k;
        }
        cout<< m<<"\n";
    }
}
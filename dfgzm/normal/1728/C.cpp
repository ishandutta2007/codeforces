#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn],b[maxn];
int work(int x){
    int s=10;
    for(int i=1;;i++){
        if((s-1)>=x)return i;
        s*=10;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        k=0;
        cin>>n;
        priority_queue<int>Q1,Q2;
        for(i=1;i<=n;i++)scanf("%d",&a[i]),Q1.push(a[i]);
        for(i=1;i<=n;i++)scanf("%d",&b[i]),Q2.push(b[i]);
        while(Q1.size()){
            if(Q1.top()==Q2.top())Q1.pop(),Q2.pop();
            else if(Q1.top()>Q2.top())Q1.push(work(Q1.top())),Q1.pop(),++k;
            else Q2.push(work(Q2.top())),Q2.pop(),++k;
        }
        cout<<k<<endl;
    }
}
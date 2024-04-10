#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
pair<int,int> d[200005];
bool u[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i].first=-a[i];
        d[i].second=i;
    }
    sort(d+1,d+1+n);
    u[d[1].second]=1;
    for(int i=2;i<=n;i++){
        int cur=d[i].second;
        if(u[cur+1]||u[cur-1]){
            u[cur]=1;
        }else{
            cout<<"nO"<<endl;
            return 0;
        }
    }
    cout<<"yEs"<<endl;
    return 0;

    return 0;
}
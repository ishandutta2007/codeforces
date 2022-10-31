#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return (a.f<b.f);
}
int n;
pair<int,int> a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].f>>a[i].s;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<n;++i){
        if (a[i].s>a[i+1].s){
            cout<<"Happy Alex";
            return 0;
        }
    }
    cout<<"Poor Alex";
}
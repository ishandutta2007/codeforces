#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[100001];
inline bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<a[1].second;++i)
        cout<<'\n';
    a[0].second=a[1].second;
    for (int i=1;i<=n;++i){
        if (a[i].second<=a[i-1].second) { a[i].second=a[i-1].second; cout<<a[i].first<<" ";}
        else {
            for (int j=a[i-1].second;j<a[i].second;++j)
                cout<<'\n';
            cout<<a[i].first<<" ";
        }
    }

}
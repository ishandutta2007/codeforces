#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
bool used[100001];
long long ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        used[a[i]]=true;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<n;++i){
        if (a[i]==a[i+1]){
            for (int j=a[i]+1;;++j){
                if (used[j]==false){
                    used[j]=true;
                    ans+=j-a[i];
                    break;
                }
            }
        }
    }
    cout<<ans;
}
#include<bits/stdc++.h>
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define sqr(a) ((a)*(a))

using namespace std;
map<long long,bool>used;
long long a[100001],b[100001],n,ans;
long long x;
int j;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (used[a[i]]==false) {
            ++j;
            used[a[i]]=true;
            b[j]=a[i];
            if (j>3) {
                cout<<"NO";
                return 0;
            }
        }
    }
    sort(b,b+4);
    x=b[2]-b[1];
    if (j==3&&b[1]+x==b[2] && b[3]-x==b[2]) cout<<"YES";
    else if (j<=2) cout<<"YES";
    else cout<<"NO";
}
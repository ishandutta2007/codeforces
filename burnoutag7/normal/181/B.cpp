#include<bits/stdc++.h>
using namespace std;

int n;
pair<float,float> a[3005];
int ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("not.txt","r",stdin);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float x=(a[i].first+a[j].first)/2.0;
            float y=(a[i].second+a[j].second)/2.0;
            int pos;
            pos=lower_bound(a,a+n,make_pair(x,y))-a;
            if(a[pos].first==x&&a[pos].second==y)ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
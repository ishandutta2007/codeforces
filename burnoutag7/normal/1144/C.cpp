#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
vector<int> vi,vd;
bool u[200005];
int usd;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n;
    vi.push_back(-1);
    vd.push_back(1e9);
    for(int i=1;i<=n;i++){
        if(!u[i]&&a[i]>vi[vi.size()-1]){
            vi.push_back(a[i]);
            u[i]=true;
        }
    }
    for(int i=n;i>=1;i--){
        if(!u[i]&&a[i]<vd[vd.size()-1]){
            vd.push_back(a[i]);
            u[i]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!u[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    cout<<vi.size()-1<<endl;
    for(int i=1;i<vi.size();i++){
        cout<<vi[i]<<' ';
    }
    cout<<endl;
    cout<<vd.size()-1<<endl;
    for(int i=1;i<vd.size();i++){
        cout<<vd[i]<<' ';
    }
    cout<<endl;

    return 0;
}
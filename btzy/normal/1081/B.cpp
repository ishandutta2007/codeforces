#include <bits/stdc++.h>
using namespace std;

vector<int> dat[100001];
int arr[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        int net=n-tmp;
        dat[net].emplace_back(i);
    }
    int hatcol=1;
    for(int i=1;i<=n;++i){
        if(dat[i].size()%i!=0){
            cout<<"Impossible\n";
            return 0;
        }
        int w=dat[i].size()/i;
        for(int j=0;j<w;++j){
            for(int k=0;k<i;++k){
                arr[dat[i][j*i+k]]=hatcol;
            }
            ++hatcol;
        }
    }
    cout<<"Possible\n";
    for(int i=0;i<n;++i){
        if(i>0)cout<<' ';
        cout<<arr[i];
    }
    cout<<'\n';
}
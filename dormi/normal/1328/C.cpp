#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<int> arr[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int larger=-1;
        char a;
        arr[1].clear(),arr[0].clear();
        for(int i=0;i<n;i++){
            cin>>a;
            if(a=='2'){
                if(larger!=-1){
                    arr[larger].push_back(0);
                    arr[(larger+1)%2].push_back(2);
                }
                else{
                    arr[1].push_back(1);
                    arr[0].push_back(1);
                }
            }
            else if(a=='1'){
                if(larger!=-1){
                    arr[larger].push_back(0);
                    arr[(larger+1)%2].push_back(1);
                }
                else{
                    larger=0;
                    arr[1].push_back(0);
                    arr[0].push_back(1);
                }
            }
            else{
                arr[1].push_back(0);
                arr[0].push_back(0);
            }
        }
        for(int x:arr[0])printf("%d",x);
        printf("\n");
        for(int x:arr[1])printf("%d",x);
        printf("\n");
    }
    return 0;
}
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int arr[200000];
bool passed[200001]={false};
vector<int> missing;
int tmp[200000];
int cts[200001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        ++cts[arr[i]];
    }
    copy(arr,arr+n,tmp);
    sort(tmp,tmp+n);
    int* tmp_end=unique(tmp,tmp+n);
    int* tmp_it=tmp;
    for(int i=1;i<=n;++i){
        if(tmp_it<tmp_end&&i==*tmp_it){
            ++tmp_it;
        }
        else{
            missing.push_back(i);
        }
    }
    int refct=0;
    auto it=missing.begin();
    for(int i=0;i<n;++i){
        if(cts[arr[i]]>1){
            if(!passed[arr[i]]&&arr[i]<*it){
                passed[arr[i]]=true;
            }
            else{
                --cts[arr[i]];
                arr[i]=*it++;
                ++refct;
            }
        }
    }
    cout<<refct<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
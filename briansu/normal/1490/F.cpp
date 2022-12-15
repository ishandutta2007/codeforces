#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> items;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            items[temp]++;

        }
        vector<int> res;
        for(auto p:items){
            res.push_back(p.second);
        }
        sort(res.begin(),res.end());
        int index=0;
        int bigger_than_index=n;
        int smaller_than_index=0;
        long long int ret=1e18;
        while(true){

            if(index==res.size()){
                break;
            }
            ret=min(smaller_than_index+bigger_than_index-(long long int)(res.at(index)*(res.size()-index)),ret);

            int index_after=index;
            while(true){
                if(index_after>=res.size()){
                    break;
                }
                if(res.at(index_after)!=res.at(index)){
                    break;
                }
                smaller_than_index+=res.at(index_after);
                bigger_than_index-=res.at(index_after);
                index_after++;

            }

            index=index_after;
        }
    cout<<ret<<endl;
    }

}
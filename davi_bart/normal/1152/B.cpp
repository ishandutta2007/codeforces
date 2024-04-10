#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
set<int> pot2;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int pot=1;
    for(int i=0;i<31;i++){
      pot2.insert(pot-1);
      pot*=2;
    }
    int N;
    cin>>N;
    int i;
    vector<int> sol;
    for(i=0;i<41;){
        if(pot2.find(N)!=pot2.end()){
          break;
        }
        for(int j=30;j>=0;j--){
            if((N&(1<<j))>0){
                sol.push_back(j+1);
                N=N^((1<<(j+1))-1);
                break;
            }
        }
        i++;
        if(pot2.find(N)!=pot2.end()){
          break;
        }
        N++;
        i++;
    }
    cout<<i<<endl;
    for(int j=0;j<sol.size();j++){
      cout<<sol[j]<<" ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=200'000;
struct tangle{
    int other;
    bool prime; // start here
    bool visited;
    //bool newprime;
};
tangle arr[MAXN*2];
bool visit(int& low, int& high, int& fliplow, int& fliphigh){
    /*struct item{
        int index;
        bool primeness;
    };
    queue<item> q;*/
    int primehead=high;
    int secondhead=low+1;
    //bool primeness=true;
    //q.push({low, true});
    while(/*!q.empty()&&*/true){
        //item el=q.front();
        //q.pop();
        if(low==secondhead)break;
        while(low<secondhead){
            if(!arr[low].visited){
                if(arr[low].other>=primehead)return false;
                arr[low].visited=true;
                arr[arr[low].other].visited=true;
                fliplow+=!arr[low].prime;
                fliphigh+=arr[low].prime;
                primehead=arr[low].other;
                /*while(primehead>arr[low].other){
                    --primehead;
                    if(!arr[primehead].visited)q.push({primehead,!el.primeness});
                }*/
            }
            ++low;
            if(low>high)return false;
        }
        if(high==primehead)break;
        while(high>primehead){
            --high;
            if(low>high)return false;
            if(!arr[high].visited){
                if(arr[high].other<secondhead)return false;
                arr[high].visited=true;
                arr[arr[high].other].visited=true;
                fliplow+=!arr[high].prime;
                fliphigh+=arr[high].prime;
                secondhead=arr[high].other+1;
                /*while(secondhead<=arr[high].other){
                    if(!arr[secondhead].visited).q.push({secondhead,!el.primeness});
                    ++secondhead;
                }*/
            }
        }
    }
    return low<=high;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int m=2*n;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        arr[a].other=b;
        arr[a].prime=true;
        arr[a].visited=false;
        arr[b].other=a;
        arr[b].prime=false;
        arr[b].visited=false;
    }
    int low=0;
    int high=m; // past-the-end
    int ans=0;
    while(low<high){
        int fliplow=0,fliphigh=0;
        if(!visit(low,high,fliplow,fliphigh)){
            cout<<"-1\n";
            return 0;
        }
        ans+=min(fliplow,fliphigh);
    }
    cout<<ans<<'\n';
}
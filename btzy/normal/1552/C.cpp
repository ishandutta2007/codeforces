#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=100;
bool arr[2*MAXN];
pair<int,int> chords[MAXN];
bool intersect(int i, int j){
    pair<int,int> nodes[4];
    nodes[0]=make_pair(chords[i].first,0);
    nodes[1]=make_pair(chords[i].second,0);
    nodes[2]=make_pair(chords[j].first,1);
    nodes[3]=make_pair(chords[j].second,1);
    sort(nodes,nodes+4);
    return(nodes[0].second==0&&nodes[1].second==1&&nodes[2].second==0&&nodes[3].second==1)||(nodes[0].second==1&&nodes[1].second==0&&nodes[2].second==1&&nodes[3].second==0);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n,k;
        cin>>n>>k;
        fill_n(arr,2*n,false);
        pair<int,int>*chords_end=chords;
        for(int i=0;i<k;++i){
            pair<int,int>& chord=*chords_end++;
            cin>>chord.first>>chord.second;
            --chord.first;
            --chord.second;
            arr[chord.first]=true;
            arr[chord.second]=true;
        }
        vector<int> tmp;
        for(int i=0;i<2*n;++i){
            if(!arr[i])tmp.push_back(i);
        }
        for(int i=0;i<n-k;++i){
            *chords_end++=make_pair(tmp[i],tmp[n-k+i]);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(intersect(i,j)){
                    ++ans;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
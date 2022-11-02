#include <bits/stdc++.h>
using namespace std;
int answers[500];
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=k;++i){
        cout<<'?';
        for(int j=0;j<=k;++j){
            if(j!=i){
                cout<<' '<<j+1;
            }
        }
        cout<<endl;
        int idx;
        cin>>idx>>answers[i];
    }
    const auto answers_end=answers+k+1;
    sort(answers,answers_end);
    const auto it=find_if(answers,answers_end,[key=answers[0]](int x){
        return x!=key;
    });
    cout<<'!'<<' '<<distance(it,answers_end)<<endl;
}
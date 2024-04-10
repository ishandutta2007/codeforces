#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int a,b;
        cin>>a>>b;
        int total=a+b;
        // start with a
        vector<int> answers;
        {
            int bgames=total/2;
            int agames=total-bgames;
            for(int i=max(0,a-bgames);i<=min(a,agames);++i){
                answers.push_back((agames-i)+(a-i));
            }

        }
        if(total&1){
            int agames=total/2;
            int bgames=total-agames;
            for(int i=max(0,a-bgames);i<=min(a,agames);++i){
                answers.push_back((agames-i)+(a-i));
            }
        }
        sort(answers.begin(),answers.end());
        answers.erase(unique(answers.begin(),answers.end()),answers.end());
        cout<<answers.size()<<'\n';
        bool br=false;
        for(int x : answers){
            if(br)cout<<' ';
            br=true;
            cout<<x;
        }
        cout<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;

int T;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int cx=114514,cy=1919810,ans=0;
        set<pair<char,pair<int,int>>> t;
        string s;
        cin>>s;
        for(char &c:s){
            int px=cx,py=cy;
            if(c=='E')cx++;
            if(c=='S')cy--;
            if(c=='W')cx--;
            if(c=='N')cy++;
            if(t.find(make_pair(c,make_pair(cx,cy)))!=t.end())ans++;
            else{
                t.insert(make_pair(c,make_pair(cx,cy)));
                if(c=='E')t.insert(make_pair('W',make_pair(px,py)));
                if(c=='S')t.insert(make_pair('N',make_pair(px,py)));
                if(c=='W')t.insert(make_pair('E',make_pair(px,py)));
                if(c=='N')t.insert(make_pair('S',make_pair(px,py)));
                ans+=5;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
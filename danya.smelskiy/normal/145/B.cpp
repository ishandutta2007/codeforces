#include <bits/stdc++.h>
using namespace std;

int x,y,xx,yy;

inline string add(string x,char c,int y) {
    string res="";
    if (c=='7') reverse(x.begin(),x.end());
    for (int i=0;i<x.size();++i) {
        res+=x[i];
        if (x[i]==c) {
            for (int j=1;j<=y;++j)
                res+=c;
            y=0;
        }
    }
    if (c=='7') reverse(res.begin(),res.end());
    return res;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>xx>>yy;
    if (abs(xx-yy)>1) {
        cout<<"-1";
        return 0;
    }
    if (xx==yy) {
        if (x>=xx+1 && y>=xx) {
            string res="";
            for (int i=1;i<=xx+xx+1;++i)
                if (i&1) res+="4";
                else res+="7";
            x-=xx+1;
            y-=xx;
            res=add(res,'4',x);
            res=add(res,'7',y);
            cout<<res;
            return 0;
        }
        if (x>=xx && y>=xx+1) {
            string res="";
            for (int i=1;i<=xx+xx+1;++i)
                if (i&1) res+="7";
                else res+="4";
            x-=xx;
            y-=xx+1;
            res=add(res,'4',x);
            res=add(res,'7',y);
            cout<<res;
            return 0;
        }
        cout<<"-1";
        exit(0);
    }
    if (xx>yy) {
        if (x>=xx && y>=xx) {
            string res="";
            for (int i=1;i<=xx+xx;++i)
                if (i&1) res+="4";
                else res+="7";
            x-=xx;
            y-=xx;
            res=add(res,'4',x);
            res=add(res,'7',y);
            cout<<res;
            return 0;
        }
        cout<<"-1";
        exit(0);
    }
    if (x>=yy && y>=yy) {
        string res="";
        for (int i=1;i<=yy+yy;++i)
            if (i&1) res+="7";
            else res+="4";
        x-=yy;
        y-=yy;
        res=add(res,'4',x);
        res=add(res,'7',y);
        cout<<res;
        exit(0);
    }
    cout<<"-1";
}
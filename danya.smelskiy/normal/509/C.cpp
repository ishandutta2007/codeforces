#include <bits/stdc++.h>
using namespace std;



int n;


inline string get(string last,int x){
    int lastsum=0;
    string best="";
    for (int i=1;i<=last.size();++i) {
        for (int j=last[i-1]-'0'+1;j<10;++j) {
            int nw=lastsum+j;
            if (nw>x) break;
            if (x-nw<=((int)last.size()-i)*9) {
                best="";
                for (int k=1;k<i;++k)
                    best+=last[k-1];
                best+=char(j+'0');
                for (int k=i+1;k<=last.size();++k)
                    best+="0";
                int xx=x-nw;
                for (int k=last.size();k>i && xx;--k) {
                    if (xx<=9) {
                        best[k-1]=char(xx+'0');
                        xx=0;
                        continue;
                    }
                     best[k-1]='9';
                     xx-=9;
                }
                break;
            }
        }
        lastsum+=last[i-1]-'0';
    }
    if (best!="") return best;
    for (int i=last.size();;++i) {
        for (int j=1;j<=9;++j) {
            if (j>x) break;
            if (j+9*i>=x) {
                best=char(j+'0');
                for (int k=1;k<=i;++k)
                    best+="0";
                x-=j;
                for (int k=best.size();k>1 && x;--k) {
                    if (x<=9) {
                        best[k-1]=char(x+'0');
                        x=0;
                        continue;
                    }
                    best[k-1]='9';
                    x-=9;
                }
                return best;
            }
        }
    }
    return best;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin>>n;
    string last="0";
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        last=get(last,x);
        cout<<last<<'\n';
    }
}
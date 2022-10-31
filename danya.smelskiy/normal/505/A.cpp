#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    cin>>s;
    for (int i=0;i<s.size();++i){
        for (int j=0;j<26;++j){
            string k=s;
            k.insert(k.begin()+i,char('a'+j));
            int l=0;
            int r=k.size()-1;
            bool t=false;
            while (l<r){
                if (k[l]!=k[r]){
                    t=true;
                    break;
                }
                ++l;
                --r;
            }
            if (t==false){
                cout<<k;
                return 0;
            }
        }
    }
    for (int j=0;j<26;++j){
        string k=s;
        k=k+char('a'+j);
        int l=0;
        int r=k.size()-1;
        bool t=false;
        while (l<r){
            if (k[l]!=k[r]){
                t=true;
                break;
            }
            ++l; --r;
        }
        if (t==false){
            cout<<k;
            return 0;
        }
    }
    cout<<"NA";
}
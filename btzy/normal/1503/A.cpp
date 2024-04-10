#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for (int ct=0;ct<tc;++ct){
        int n;
        string str;
        cin>>n;
        cin>>str;
        bool cstr=false;
        int hint=-1;
        for(int i=0;i<n;++i){
            if(str[i]=='0'){
                cstr=!cstr;
                hint=i;
            }
        }
        if(cstr){
            cout<<"NO\n";
            continue;
        }
        string a1,a2;
        int cum=0;
        bool stall=false;
        int i;
        for(i=0;i<n;++i){
            if(str[i]=='1'){
                if((cum>1&&i<=hint)||(cum>0&&i>hint)||(cum>0&&stall)){
                    a1.push_back(')');
                    a2.push_back(')');
                    --cum;
                }
                else{
                    a1.push_back('(');
                    a2.push_back('(');
                    ++cum;
                }
            }
            else{
                if(stall){
                    a1.push_back('(');
                    a2.push_back(')');
                    ++cum;
                    stall=false;
                }
                else{
                    if(cum>0){
                        a1.push_back(')');
                        a2.push_back('(');
                        --cum;
                        stall=true;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(i<n||stall||cum>0){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<a1<<'\n'<<a2<<'\n';
    }
}
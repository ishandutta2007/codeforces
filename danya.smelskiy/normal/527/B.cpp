#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s,s1;
bool t;
int one,two;
int a[300][300];
int main(){
    cin>>n>>s>>s1;
    for (int i=0;i<s.size();++i){
        if (s[i]!=s1[i]){
            ++ans;
            char x=s[i],y=s1[i];
            if (a[y][x]>0 && t==false){
                t=true;
                one=a[y][x];
                two=i+1;
            }
            a[x][y]=i+1;
        }
    }
    if (t==true){
        cout<<ans-2<<endl<<one<<" "<<two;
        return 0;
    }
    for (int i='a';i<='z';++i){
        for (int j='a';j<='z';++j)
            if (i!=j){
            if (a[i][j]>0){
                for (int z='a';z<='z';++z){
                    if (a[j][z]>0 && j!=z){
                        cout<<ans-1<<endl<<a[j][z]<<" "<<a[i][j];
                        return 0;
                    }
                }
            }
        }
    }
    cout<<ans<<endl<<"-1 -1";
}
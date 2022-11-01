#include<bits/stdc++.h>
using namespace std;

int n;
char s[200005];
int dif;
int moFront,moBack,biFront,biBack,current;

bool FrontBigBackSmall(){
    int curDif=(moFront-biBack)*9;
    if(curDif+dif>0)return true;
    else return false;
}

bool FrontSmallBackBig(){
    int curDif=(biFront-moBack)*9;
    if(curDif+dif<0)return true;
    else return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s+1;
    for(int i=1;i<=n;i++){
        if(s[i]=='?'){
            current++;
            if(current&1){
                if(i<=n/2){
                    moFront++;
                }else{
                    moBack++;
                }
            }else{
                if(i<=n/2){
                    biFront++;
                }else{
                    biBack++;
                }
            }
        }else{
            if(i<=n/2){
                dif+=(s[i]-'0');
            }else{
                dif-=(s[i]-'0');
            }
        }
    }
    if(FrontBigBackSmall()){
        cout<<"Monocarp"<<endl;
    }else
    if(FrontSmallBackBig()){
        cout<<"Monocarp"<<endl;
    }else
    cout<<"Bicarp"<<endl;

    return 0;
}
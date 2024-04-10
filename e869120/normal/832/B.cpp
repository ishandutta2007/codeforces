#include<bits/stdc++.h>
using namespace std;
string V,S,T;int n;bool used[27];
bool hantei(string V1,string V2){
    for(int i=0;i<V1.size();i++){
        if(V1[i]=='?'){if(used[V2[i]-'a']==false)return false;}
        else if(V1[i]=='*'){if(used[V2[i]-'a']==true)return false;}
        else if(V1[i]!=V2[i])return false;
    }
    return true;
}
int main(){
    cin>>V;
    for(int i=0;i<V.size();i++)used[V[i]-'a']=true;
    cin>>S>>n;string U="",W="";bool u=false;
    for(int j=0;j<S.size();j++){
        if(S[j]!='*'){if(u==false)U+=S[j];else W+=S[j];}
        else u=true;
    }
    for(int i=0;i<n;i++){
        cin>>T;
        if((int)S.size()-(int)T.size()>=2){cout<<"NO"<<endl;continue;}
        if(S.size()==T.size()){
            if(hantei(S,T)==true){cout<<"YES"<<endl;continue;}
        }
        if(U.size()+W.size()==S.size()){cout<<"NO"<<endl;continue;}
        string W1=T.substr(0,U.size());
        string W2=T.substr(T.size()-W.size(),W.size());
        if(T.size()>=U.size()+W.size() && hantei(U,W1)==true && hantei(W,W2)==true){
            bool OK=false;
            for(int j=U.size();j<T.size()-W.size();j++){
                if(used[T[j]-'a']==true)OK=true;
            }
            if(OK==false){cout<<"YES"<<endl;continue;}
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
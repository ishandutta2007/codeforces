#include<bits/stdc++.h>
using namespace std;

int q;
bool f;
string s,t;
set<char> st;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>s>>t;
        st.clear();
        f=false;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
        }
        for(int i=0;i<t.size();i++){
            if(st.find(t[i])!=st.end())f=true;
        }
        if(s.size()==1&&s[0]!=t[0])f=false;
        if(f){
            cout<<"yEs"<<endl;
        }else{
            cout<<"nO"<<endl;
        }
    }

    return 0;
}
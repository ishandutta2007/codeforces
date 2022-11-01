#include<bits/stdc++.h>
using namespace std;

string s;
stack<int> st;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(!st.empty()){
                st.pop();
            }
        }else{
            st.push(i);
        }
    }
    while(!st.empty()){
        s[st.top()]='0';
        st.pop();
    }
    cout<<s<<endl;

    return 0;
}
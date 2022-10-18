#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=100005;
 
int t;
 
int main(){
    cin>>t;
    unsigned long long mx=(1ll<<32)-1ll;
    long long c=0;
    stack<unsigned long long> st;
    stack<unsigned long long> cn;
    st.push(1);cn.push(0);
    for(int i=1;i<=t;i++){
        char op[10];
        cin>>op;
        if(op[0]=='f'){
            unsigned long long t;cin>>t;
            st.push(t);
            cn.push(0);
        }else if(op[0]=='e'){
            unsigned long long cur=st.top();st.pop();
            unsigned long long cuc=cn.top();cn.pop();
            unsigned long long ans=cur*cuc;
            cn.top()+=ans;
            if(cn.top()>mx||ans>mx){
                cout<<"OVERFLOW!!!";
                return 0;
            }
        }else if(op[0]=='a'){
            cn.top()++;
            if(cn.top()>mx){
                cout<<"OVERFLOW!!!";
                return 0;
            }
        }
    }
    if(cn.top()>mx){
                cout<<"OVERFLOW!!!";
                return 0;
            }
    cout<<cn.top();
    return 0;
}
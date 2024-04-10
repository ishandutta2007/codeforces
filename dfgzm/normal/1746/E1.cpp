#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m;
set<int>S;
vector<int>V;
bool A(int x){
    cout<<"! "<<x<<endl;
    string S;cin>>S;
    return S==":)";
}
bool Q(set<int> &s){
    cout<<"? "<<s.size();
    for(auto i:s)cout<<' '<<i;
    cout<<endl;string S;cin>>S;
    return S=="YES";
}
void work3(set<int> S){
    if(S.size()<=2){
        int x=*S.begin();S.erase(x);
        int y=*S.begin();S.erase(y);
        if(!A(x))A(y);
        exit(0);
    }
    set<int>S1,S2,S3;
    int len=S.size();
    for(int i=1;i<=len/3;i++)S1.insert(*S.begin()),S.erase(S.begin());
    for(int i=1;i<=len/3;i++)S2.insert(*S.begin()),S.erase(S.begin());
    for(int i=1;i<=len-len/3-len/3;i++)S3.insert(*S.begin()),S.erase(S.begin());
    if(Q(S1)){
        if(Q(S2)){
            set<int>tmp;
            for(int x:S1)tmp.insert(x);
            for(int x:S2)tmp.insert(x);
            work3(tmp);
        }else{
            set<int>tmp;
            for(int x:S1)tmp.insert(x);
            for(int x:S3)tmp.insert(x);
            work3(tmp);
        }
    }else{
        if(Q(S1)){
            if(Q(S2)){
                set<int>tmp;
                for(int x:S1)tmp.insert(x);
                for(int x:S2)tmp.insert(x);
                work3(tmp);
            }else{
                set<int>tmp;
                for(int x:S1)tmp.insert(x);
                for(int x:S3)tmp.insert(x);
                work3(tmp);
            }
        }else{
            set<int>tmp;
            for(int x:S2)tmp.insert(x);
            for(int x:S3)tmp.insert(x);
            work3(tmp);
        }
    }
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++)S.insert(i);
    work3(S);
}
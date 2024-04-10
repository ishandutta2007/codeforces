#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<pair<int,string> > ans;

void print(){
    int cnt=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i].first)cnt++;
    }
    assert(cnt<=3000);
    cout<<cnt<<endl;
    for(int i=0;i<ans.size();i++){
        if(ans[i].first)cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
    exit(0);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    if(k>4*n*m-2*n-2*m){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<n;i++){
        if(k>(m-1)*3){
            if(i&1){
                ans.push_back(make_pair(m-1,"DUR"));
            }else{
                ans.push_back(make_pair(m-1,"DUL"));
            }
            k-=(m-1)*3;
        }else{
            if(i&1){
                ans.push_back(make_pair(k/3,"DUR"));
            }else{
                ans.push_back(make_pair(k/3,"DUL"));
            }
            k%=3;
            if(k==1)ans.push_back(make_pair(1,"D"));
            if(k==2)ans.push_back(make_pair(1,"DU"));
            print();
        }
        if(k){
            k--;
            ans.push_back(make_pair(1,"D"));
        }
        if(k==0)print();
    }
    if(k>m-1){
        if(n&1){
            ans.push_back(make_pair(m-1,"R"));
        }else{
            ans.push_back(make_pair(m-1,"L"));
        }
        k-=m-1;
    }else{
        if(n&1){
            ans.push_back(make_pair(k,"R"));
        }else{
            ans.push_back(make_pair(k,"L"));
        }
        print();
    }
    if(k>m-1){
        if(n&1){
            ans.push_back(make_pair(m-1,"L"));
        }else{
            ans.push_back(make_pair(m-1,"R"));
        }
        k-=m-1;
    }else{
        if(n&1){
            ans.push_back(make_pair(k,"L"));
        }else{
            ans.push_back(make_pair(k,"R"));
        }
        print();
    }
    for(int i=n;i>1;i--){
        k--;
        ans.push_back(make_pair(1,"U"));
        if(k==0)print();
        if(k>m-1){
            if(i&1){
                ans.push_back(make_pair(m-1,"R"));
            }else{
                ans.push_back(make_pair(m-1,"L"));
            }
            k-=m-1;
        }else{
            if(i&1){
                ans.push_back(make_pair(k,"R"));
            }else{
                ans.push_back(make_pair(k,"L"));
            }
            print();
        }
    }

    return 0;
}
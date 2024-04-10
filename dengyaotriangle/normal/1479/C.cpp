#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int l,r;
    cin>>l>>r;
    cout<<"YES\n";
    int sp=r-l;
    if(sp==0){
        cout<<"2 1\n1 2 "<<l;
        return 0;
    }else if(sp==1){
        cout<<"3 3\n1 3 "<<l<<'\n'<<"1 2 1\n"<<"2 3 "<<l;
        return 0;
    }
    int ord=0;
    bool flg=0;
    if(l==1){
        l++;flg=1;sp--;
    }
    while((1<<(ord+1))-1<=sp)ord++;
    vector<int> eu,ev,ew;
    int s=2;
    int n=2+ord+1;
    if(flg){
        eu.push_back(1);ev.push_back(n);ew.push_back(1);
    }
    eu.push_back(1);ev.push_back(2);ew.push_back(l-1);
    for(int i=s;i<=s+ord;i++){
        eu.push_back(i);ev.push_back(n);ew.push_back(1);
    }
    for(int i=s+ord,f=1;i>=s;i--,f<<=1){
        for(int j=s;j<i;j++){
            eu.push_back(j);ev.push_back(i);ew.push_back(f);
        }
    }
    int p=(1<<ord)-1;
    for(int i=ord-1,j=1;i>=0;i--,j++){
        int w=(1<<i);
        if(p+w<=sp){
            eu.push_back(1);ev.push_back(s+j);ew.push_back(p+l);
            p+=w;
        }
    }
    assert(p==sp);
    cout<<n<<' '<<eu.size()<<endl;
    for(int i=0;i<eu.size();i++)cout<<eu[i]<<' '<<ev[i]<<' '<<ew[i]<<endl;
    return 0;
}
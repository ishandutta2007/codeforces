#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int n,k;
    cin>>n>>k;
    cout<<"or 1 2"<<endl;
    int x1;cin>>x1;
    cout<<"and 1 2"<<endl;
    int y1;cin>>y1;
    cout<<"or 1 3"<<endl;
    int x2;cin>>x2;
    cout<<"and 1 3"<<endl;
    int y2;cin>>y2;
    cout<<"or 2 3"<<endl;
    int x3;cin>>x3;
    cout<<"and 2 3"<<endl;
    int y3;cin>>y3;
    vector<int> res(n+1);
    for(int i=30;i>=0;i--){
        int c1=((x1>>i)&1)+((y1>>i)&1);
        int c2=((x2>>i)&1)+((y2>>i)&1);
        int c3=((x3>>i)&1)+((y3>>i)&1);
        if(c1==0){
            res[3]+=c3<<i;
        }else if(c1==2){
            res[1]+=1<<i;
            res[2]+=1<<i;
            res[3]+=(c3-1)<<i;
        }else{
            if(c2==1){
                if(c3==0){
                    res[1]+=1<<i;
                }else{
                    res[2]+=1<<i;
                    res[3]+=1<<i;
                }
            }else if(c2==0){
                res[2]+=1<<i;
            }else{
                res[1]+=1<<i;
                res[3]+=1<<i;
            }
        }
    }
    for(int i=4;i<=n;i++){
        cout<<"or 1 "<<i<<endl;
        int x,y;
        cin>>x;
        cout<<"and 1 "<<i<<endl;
        cin>>y;
        res[i]=x+y-res[1];
    }
    sort(res.begin()+1,res.end());
    cout<<"finish "<<res[k]<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,s[3350],im[10005];

bool ask(int x,int y=-1,int z=-1){
    if(y==-1)y=x+1;
    if(z==-1)z=y+1;
    cout<<"? "<<x+1<<' '<<y+1<<' '<<z+1<<endl;
    bool res;
    cin>>res;
    return res;
}

void print(){
    cout<<"! ";
    int cnt=0;
    for(int i=0;i<n;i++)cnt+=im[i]==2;
    cout<<cnt<<' ';
    for(int i=0;i<n;i++)if(im[i]==2)cout<<i+1<<' ';
    cout<<endl;
}

void mian(){
    cin>>n;
    memset(im,0,n*4);
    for(int i=0;i<n;i+=3){
        s[i/3]=ask(i);
    }
    int fc,fi;
    for(int i=0;i<n/3;i++)if(s[i]!=s[i+1]){
        bool f[]={s[i],ask(i*3+1),ask(i*3+2),s[i+1]};
        for(int j=0;j<3;j++)if(f[j]!=f[j+1]){
            fc=i*3+j+3;
            fi=i*3+j;
            if(f[j])swap(fc,fi);
            im[fc]=1;
            im[fi]=2;
            break;
        }
        for(int j=i*3;j<i*3+6;j++)if(j!=fc&&j!=fi){
            im[j]=2-ask(j,fc,fi);
        }
        break;
    }
    for(int i=0;i<n/3;i++)if(i!=fc/3&&i!=fi/3){
        if(s[i]){//more crewmates
            if(ask(i*3,i*3+1,fi)){
                im[i*3]=im[i*3+1]=1;
                im[i*3+2]=2-ask(i*3+2,fc,fi);
            }else{
                im[i*3+2]=1;
                im[i*3]=2-ask(i*3,fc,fi);
                im[i*3+1]=im[i*3]^3;
            }
        }else{
            if(!ask(i*3,i*3+1,fc)){
                im[i*3]=im[i*3+1]=2;
                im[i*3+2]=2-ask(i*3+2,fc,fi);
            }else{
                im[i*3+2]=2;
                im[i*3]=2-ask(i*3,fc,fi);
                im[i*3+1]=im[i*3]^3;
            }
        }
    }
    print();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
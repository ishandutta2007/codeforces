#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=50;
bool answer[MAXN][MAXN];
int n;
void query(int a,int b,int c,int d){
    cout<<"? "<<a+1<<' '<<b+1<<' '<<c+1<<' '<<d+1<<endl;
}
void flip(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if((i+j)&1){
                answer[i][j]=!answer[i][j];
            }
        }
    }
}
void print(){
    cout<<"!\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<answer[i][j];
        }
        cout<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    answer[0][0]=true;
    answer[0][1]=true;
    for(int i=0;i<2;++i){
        query(0,i,1,i+1);
        int tmp;
        cin>>tmp;
        answer[1][i+1]=answer[0][i]^!tmp;
    }
    for(int j=0;j<n-2;++j){
        query(0,j,0,j+2);
        int tmp;
        cin>>tmp;
        answer[0][j+2]=answer[0][j]^!tmp;
    }
    {
        query(1,0,1,2);
        int tmp;
        cin>>tmp;
        answer[1][0]=answer[1][2]^!tmp;
    }
    for(int j=1;j<n-2;++j){
        query(1,j,1,j+2);
        int tmp;
        cin>>tmp;
        answer[1][j+2]=answer[1][j]^!tmp;
    }
    for(int i=0;i<n-2;++i){
        for(int j=0;j<n;++j){
            query(i,j,i+2,j);
            int tmp;
            cin>>tmp;
            answer[i+2][j]=answer[i][j]^!tmp;
        }
    }
    //print();
    for(int i=0;i<n-1;++i){
        if(answer[i][i]==answer[i+1][i+1]&&answer[i][i]==false){
            if(answer[i-1][i]==answer[i+1][i]){
                query(i-1,i,i+1,i+1);
                int tmp;
                cin>>tmp;
                if(answer[i-1][i]^!tmp)flip();
            }
            else{
                query(i-1,i-1,i+1,i);
                int tmp;
                cin>>tmp;
                if(answer[i-1][i]^!tmp)flip();
            }
            print();
            return 0;
        }
    }
    for(int i=n-1;i>=0;--i){
        if(answer[i][i]==answer[i-1][i-1]&&answer[i][i]==true){
            if(answer[i-1][i]==answer[i+1][i]){
                query(i-1,i-1,i+1,i);
                int tmp;
                cin>>tmp;
                if(answer[i-1][i]^!!tmp)flip();
            }
            else{
                query(i-1,i,i+1,i+1);
                int tmp;
                cin>>tmp;
                if(answer[i-1][i]^!tmp)flip();
            }
            print();
            return 0;
        }
    }
}
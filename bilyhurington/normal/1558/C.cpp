#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,A[2100];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&A[i]);
    for(int i=1;i<=n;i++){
        if(A[i]%2!=i%2){
            puts("-1");
            return;
        }
    }
    vector<int> Ans;
    for(int i=n;i>=3;i-=2){
        int x=0,y=0;
        for(int j=1;j<=n;j++){
            if(A[j]==i) x=j;
        }
        Ans.push_back(x);
        reverse(A+1,A+x+1);
        for(int j=1;j<=n;j++){
            if(A[j]==i-1) y=j;
        }
        Ans.push_back(y-1);
        reverse(A+1,A+y);
        if(i>3){
            Ans.push_back(y+1);
            reverse(A+1,A+y+2);
            Ans.push_back(3);
            reverse(A+1,A+4);
        }
        Ans.push_back(i);
        reverse(A+1,A+i+1);
    }
    printf("%d\n",(int)Ans.size());
    for(auto x:Ans) printf("%d ",x);
    puts("");
    // for(int i=1;i<=n;i++) printf("%d ",A[i]);
    // puts("");
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--) solve();
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
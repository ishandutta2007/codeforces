#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,a,b;
bool vis[200010];
void solve(){
    int t1=(a+b+1)/2,t2=a+b-t1;
    if(a<t1){
        for(int i=0;i<=a;i++){
            vis[t2-i+a-i]=1;
        }
    }else{
        for(int i=0;i<=b;i++){
            vis[t1-i+b-i]=1;
        }
    }
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        for(int i=0;i<=a+b;i++) vis[i]=0;
        solve();
        swap(a,b);
        solve();
        vector<int> vec;
        for(int i=0;i<=a+b;i++) if(vis[i]) vec.push_back(i);
        printf("%d\n",(int)vec.size());
        for(auto x:vec) printf("%d ",x);
        puts("");
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
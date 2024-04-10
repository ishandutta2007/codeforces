#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back

  long n, m;
  long a = 1<<18;
 long long d[(1<<18) + 5][105]; 

int masks[500000];
int newmasks[500000];
int used[500000];
int cursz = 0;
int newsz = 0;
int nums[20];
int ddd[10];
long long fac(int N){
    long long res = 1;
    for(int i = 1; i <= N; ++i)
        res*=i;
    return res;
}
int main(){
    long long N;
    int m;
    cin>>N>>m;
    int cnt = 0;
    while(N){
        nums[cnt] = N%10;
        ddd[N%10]++;
        ++cnt;
        N/=10;
    }
    for(int i =0; i < cnt; ++i){
        if(nums[i] != 0){
            d[1<<i][nums[i]%m] = 1;
            masks[cursz] = 1<<i;
            ++cursz;
        }
        
    }
    for(int i = 1; i < cnt; ++i){
        newsz = 0;
        for(int j = 0; j < cursz; ++j){
            for(int dig = 0; dig < cnt; ++dig){
                //cerr<<masks[j]<<" "<<(1<<dig)<<endl;
                if((masks[j]&(1<<dig) ) == 0){
                    //cerr<<"Ok"<<endl;
                    int curmask = masks[j]^(1<<dig);
                    if(!used[curmask]){
                        newmasks[newsz] = curmask;
                        ++newsz;
                        used[curmask]= true;
                    }
                    for(int mod = 0; mod < m; ++mod){
                        d[curmask][(10*mod + nums[dig])%m] += d[masks[j]][mod];
                    }
                }
            }
        }
        cursz = newsz;
        for(int j = 0; j < cursz; ++j){
            masks[j] = newmasks[j];
        }
    }
    long long res = d[(1<<cnt) - 1][0];
    for(int i =0; i < 10; ++i){
        res/=fac(ddd[i]);
    }
    cout<<res;
}
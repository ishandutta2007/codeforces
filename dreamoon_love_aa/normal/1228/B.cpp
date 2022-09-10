#include <bits/stdc++.h>
using namespace std;
int h,w,c[1010],r[1010],AA[1010][1010]={};
int main() {
    cin >> h >> w;
    int flag = 1;
    for(int i = 1; i<= h; i++){
        cin >> r[i];
    }
    for(int i = 1; i<=w; i++){
        cin >> c[i];
    }
    for(int i = 1; i<= h; i++){
       
        if(r[i] == 0){
            AA[i][1] = 1;
        }else{
            int k;
            for( k = 1; k <= r[i]; k++)
                    AA[i][k] = -1;
            
            if(r[i] < w)
             AA[i][k] = 1;
            
        }
    }
    for(int i = 1; i<=w; i++){
        if(c[i] == 0){
             if(AA[1][i] == -1)
                    flag = 0;
            AA[1][i] = 1;
        }else{
            int k;
            for( k = 1; k <= c[i]; k++){
                if(AA[k][i] == 1)
                    flag = 0;
                 AA[k][i] = -1;
                 // cout <<i<<" "<< k <<" : "<< flag << endl;
            }
            if(c[i] < h){
                if(AA[k][i] == -1)
                    flag = 0;
             AA[k][i] = 1;
            }
 
        }
    }
    //cout << flag << endl;
    if(flag == 0)
        cout << 0 << endl;
    else{
        int sum = 1;
        for(int i = 1; i<=h;i++){
            for(int j = 1; j <=w;j++){
                //scout << AA[i][j] << " " ;
                if(AA[i][j] == 0)
                    sum=sum*2%(1000000007);
                    
            }
           // cout << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
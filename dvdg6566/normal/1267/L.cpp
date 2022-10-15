#include <cstdio>
#include <algorithm>
#include <string>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
int r,c,k;

string fin[1005];
char arr[1000005];
deque<char> dq;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    scanf("%d%d%d",&r,&c,&k);
    k--;
    
    scanf("%s",&arr);
    
    sort(&arr[0],&arr[r*c]); 
    for (int x=0;x<r*c;x++){
        dq.push_back(arr[x]);
    }
    
    int L=0, R=r-1;
    for (int x=0;x<c;x++){
        for (int x=L;x<=R;x++){
            if (x<=k) fin[x]+=dq.front(),dq.pop_front();
            else fin[x]+=dq.back(),dq.pop_back();
        }
        
        while (fin[L][x]!=fin[k][x]){
            while(fin[L].size()!=c){
                fin[L]+=dq.back();
                dq.pop_back();
            }
            L++;
        }
        
        while (fin[R][x]!=fin[k][x]){
            while (fin[R].size()!=c){
                fin[R]+=dq.back();
                dq.pop_back();
            }
            R--;
        }
        //printf("%d %d\n",L,R);
    }
    
    sort(&fin[0],&fin[r]);
    
    for (int x=0;x<r;x++){
        cout<<fin[x]<<'\n';
    }
}
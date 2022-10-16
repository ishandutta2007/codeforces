//  228

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    char a;
    cin>>n>>m>>a;
    char arr[n][m];
    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
                cin>>arr[i][j];
          }
    }
    
    char sam[n*m];
    int x=0,p=0,sum=0;
    
    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
                if(arr[i][j]==a){
                      if(i-1>=0 && arr[i-1][j]!='.' && arr[i-1][j]!=a){
                            for(int k=0;k<x;k++){
                                  if(sam[k]==arr[i-1][j]){
                                        p++;
                                        break;
                                  }
                            }
                            if(p==0){
                                  sam[x]=arr[i-1][j];//cout<<sam[x];
                                  x++;
                                  sum++;
                            }
                            p=0;
                      }
                      if(i+1<=n-1 && arr[i+1][j]!='.' && arr[i+1][j]!=a){
                            for(int k=0;k<x;k++){
                                  if(sam[k]==arr[i+1][j]){
                                        p++;
                                        break;
                                  }
                            }
                            if(p==0){
                                  sam[x]=arr[i+1][j];//cout<<sam[x];
                                  x++;
                                  sum++;
                            }
                            p=0;    
                      }
                      if(j-1>=0 && arr[i][j-1]!='.' &&  arr[i][j-1]!=a){
                             for(int k=0;k<x;k++){
                                  if(sam[k]==arr[i][j-1]){
                                        p++;
                                        break;
                                  }
                            }
                            if(p==0){
                                  sam[x]=arr[i][j-1];//cout<<sam[x];
                                  x++;
                                  sum++;
                            }
                            p=0;     
                      }
                      if(j+1<=m-1 && arr[i][j+1]!='.' && arr[i][j+1]!=a){
                             for(int k=0;k<x;k++){
                                  if(sam[k]==arr[i][j+1]){
                                        p++;
                                        break;
                                  }
                            }
                            if(p==0){
                                  sam[x]=arr[i][j+1];//cout<<sam[x];
                                  x++;
                                  sum++;
                            }
                            p=0;     
                      }
                }
          }
    }
    
    cout<<sum;
    
    return 0;
}
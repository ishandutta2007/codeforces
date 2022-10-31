#include<bits/stdc++.h>
using namespace std;
 
const int N = 1000*100 + 10 , L = 26;
 
int lazy[N*4][L+5] , tr[N*4][L+5] , n;
vector <int> v;
 
void shift(int b , int mid , int e , int ind , int st){
    
    if(lazy[ind][st]){
         lazy[ind*2][st] = lazy[ind*2 + 1][st] = lazy[ind][st];
 
         int a = lazy[ind][st] - 1;
 
         tr[ind*2][st] = (mid - b) * a;
         tr[ind*2 + 1][st] = (e - mid) * a;
         
         lazy[ind][st] = 0;
    } 
    
    return;
}
 
void add(int st , int l , int r , int val , int b = 0 , int e = n , int ind = 1){
    
    if(l <= b && e <= r){
        tr[ind][st] = (e - b)*val;
        lazy[ind][st] = val + 1;
        return;
    }
 
    int mid = (b + e)/2;
    shift(b , mid , e , ind , st);
 
    if(l < mid)
        add(st , l , r , val , b , mid , ind*2);
    if(r > mid)
        add(st , l , r , val , mid , e , ind*2 + 1);
 
    tr[ind][st] = tr[ind*2][st] + tr[ind*2 + 1][st];
    return;
 
}
 
int get(int st , int l , int r , int b = 0 , int e = n , int ind = 1){
    
    if(l <= b && e <= r)
        return tr[ind][st];
    
    int mid = (b + e)/2 , ret = 0;
    shift(b , mid , e , ind , st);
 
    if(l < mid)
        ret += get(st , l , r , b , mid , ind*2);
    if(r > mid)
        ret += get(st , l, r , mid , e , ind*2 + 1);
    
    return ret;
}
 
int main(){
 
     ifstream fin("input.txt");
     ofstream fout("output.txt");
 
     int m , l , r , t , ml , mr;
     char ch;
 
     fin >> n >> m;
 
     for(int i = 0 ; i < n ; i++){
          fin >> ch;
          add((int) ch - 97 , i , i+1 , 1);
     }
     
     for(int i = 0 ; i < m ; i++){
 
            fin >> l >> r;
            l-- , t = 0 , ml = l , mr = r;            
            v.clear();
            
 
            for(int j = 0 ; j < L ; j++){
                 
                 v.push_back(get(j , l , r));
 
                 if(v[j] % 2)
                     t++;                 
            }
            
                           
            if(t < 2){
                for(int j = 0 ; j < L ; j++){
                        add(j , ml , mr , 0);
                        int k = v[j]/2;
                        if(k){
                            add(j , l , l + k , 1);
                            add(j , r - k , r , 1);
 
                            l+= k;
                            r-= k;
                        }
 
                        if(v[j]%2){
                            int z = (l + r)/2;
                            add(j , z , z + 1 , 1);
                        }    
                }
            }
     }
     
     for(int i = 0 ; i < n ; i++)
           for(int j = 0 ; j < L ; j++)
                if(get(j , i , i+1))
                     fout << (char) (j + 97);
           
     cout << endl;
     return 0;
 
}
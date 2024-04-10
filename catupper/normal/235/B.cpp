#include<iostream>
#include<cstdio>
#include<algorithm>
 
using namespace std;
 
double num[105000];
int n;
 
double solve(int left, int right){
    if(left + 1 == right) return num[left];
        double p = 1, q = 1, a = 0, b = 0;
        int mid = (left + right) / 2;
        for(int i = 1,j = mid - 1;j >= left;i++,j--){
                p *= num[j];
                if(j == left) a += p * i;
                else a += p * (1 - num[j - 1]) * i;
        }
        for(int i = 1, j = mid;j < right;i++, j++){
                q *= num[j];
                if(j == right -
                 1) b += q * i;
                else b += q * (1 - num[j + 1]) * i;
        }
        return solve(left, mid) + solve(mid, right) + 2 * a * b;
}
 
int main(){
        cin >> n ;
        for(int i = 0;i < n;i++){
                cin >> num[i];
        }
        printf("%f\n", solve(0, n));
        return 0;
}
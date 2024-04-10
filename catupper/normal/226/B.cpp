#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int n, nums[100001];
long long int ruiseki[100001];

long long int sumof(int x,long long int y){
  if(y >= n)y = n - 1;
  if(x == 0)return ruiseki[y];
  return ruiseki[y] - ruiseki[x - 1];
}

long long int solve(int x){
  long long int from = 1, num = x, seki = 1;
  long long int res = 0;
  while(from < n){
    res += sumof(from, from + num - 1) * seki;
    seki++;
    from += num;
    num *= x;
  }
  return res;
}

long long int answers[100001];

int main(){

  scanf("%d", &n);
  for(int i = 0;i < n;i++)
    scanf("%d", nums + i);
  sort(nums, nums + n, greater<int>());
  ruiseki[0] = nums[0];
  for(int i = 1;i < n;i++){
    ruiseki[i] = ruiseki[i - 1] + nums[i];
  }
  for(int i = 1;i <= 100000;i++){
    answers[i] = solve(i);
  }
  scanf("%d", &n);
  for(int i = 0;i < n;i++){
    int q;
    scanf("%d", &q);
    if(i != 0)putchar(' ');
    cout << answers[q];
  }
  puts("");
  return 0;  
}
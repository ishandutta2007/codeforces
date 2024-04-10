#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

long long bit[210000];
long long n, op, a, b, x;
void add(long long pos, long long val){
    while(pos < 210000){
	bit[pos] += val;
	pos += pos & -pos;
    }
}

long long val(long long pos){
    long long res = 0;
    while(pos){
	res += bit[pos];
	pos -= pos & -pos;
    }
    return res;
}

int main(){
    long long  sum = 0;
    long long array_size = 1;
    cin >> n;
    for(long long i = 0;i < n;i++){
	cin >> op;
	if(op == 1){
	    cin >> a >> b;
	    a = min(a, array_size);
	    add(1, b);
	    add(a + 1, -b);
	    sum += a * b;
	}
	if(op == 2){
	    cin >> x;
	    sum += x;
	    array_size++;
	    add(array_size, x);
	    add(array_size + 1, -x);
	}
	if(op == 3 && array_size >= 2){
	    long long m = val(array_size);
	    add(array_size, -m);
	    add(array_size + 1, m);
	    sum -= m;
	    array_size--;
	}
	printf("%f\n", (double)sum / (double)array_size);
    }
    return 0;
}
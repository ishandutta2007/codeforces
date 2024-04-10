#include <cstdio>
int n, m, ans;
int main(){
    scanf("%d%d", &n, &m);
    if(n > m) n ^= m ^= n ^= m;
    switch(n){
    	case 1:{
    		ans = (m / 3 + (m % 3?1 : 0));
			break;
		}
		case 2:{
			ans = ((m >> 1) + 1);
			break;
		}
		case 3:{
			ans = (m - ((m - 1) >> 2));
			break;
		}
		case 4:{
			if(m == 4 || m == 7 || m == 8 || m == 10) ans = m;
			else ans = m + 1;
			break;
		}
		case 5:{
			if(m >= 5 && m <= 7) ans = (m + 2);
			else if(m == 8) ans = 11;
			break;
		}
		default :{
			ans = 10;
			break;
		}
	}
	printf("%d\n", n * m - ans);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
using ldd=long double;
#define endl "\n"
const ldd PI=acos(-1.0);
const int ITERATIONS = 60;
const int PRECISION = 11;
 
struct Point{
    lol x,y;
    Point& operator-=(const Point& rhs){
        x-=rhs.x,y-=rhs.y;
        return *this;
    }
    friend Point operator-(Point lhs,const Point& rhs){
        lhs -= rhs;
        return lhs;
    }
};
std::istream& operator>>(std::istream& is, Point& obj){
    is>>obj.x>>obj.y;
    return is;
}
 
ldd norm(Point p){
    return p.x*p.x+p.y*p.y;
}
ldd cross_product(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}
ldd dot_product(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}
ldd getalpha(Point a,Point b,Point c){
    return atan2l(cross_product(c-b,a-b),dot_product(c-b,a-b));
}
ldd getarea(Point a,Point b,Point c){
    Point l1=c-b,l2=a-b;
    return (dot_product(l1,l2)/cross_product(l1,l2)+atan2l(cross_product(l1,l2),-dot_product(l1,l2))*((norm(l1)*norm(l2))/(cross_product(l1,l2)*cross_product(l1,l2))+2.0))/16.0;
}
 
ldd f(ldd theta, ldd alpha){
	return -cos(theta)+(1.0/tan(alpha))*sin(theta) + (cos(theta)*(1.0/tan(alpha))+sin(theta)) * (sin(2*theta)/2.0);
}
ldd g(ldd theta, ldd alpha){
	return (cos(theta)*(1.0/tan(alpha))+sin(theta)) * (1.0 - cos(2*theta))/2.0;
}
ldd get_x(ldd y, ldd alpha, ldd & theta){
	ldd lo = alpha, hi = PI;
	for(int it = 0; it < ITERATIONS; ++it){
		theta = (lo + hi) / 2.0;
		ldd y_guess = g(theta, alpha);
		if(y > y_guess){
			hi = theta;
		}else{
			lo = theta;
		}
	}
 
	return f(theta, alpha);
}
ldd A(ldd theta, ldd alpha){
	return (sin(2 * (alpha - 3 * theta)) - sin(2 * (alpha - 2 * theta)) - 4 * sin(2 * (alpha - theta)) - sin(2 * (alpha + theta))
			- 4 * theta * cos(2 * alpha) + 8 * theta - 2 * sin(4 * theta)) / (64.0 * sin(alpha) * sin(alpha));
}
ldd find_overlap_area(ldd alpha_1, ldd alpha_2, ldd L){
 
	ldd lo = 0, hi = sin(max(alpha_1, alpha_2));
	ldd theta_1 = PI, theta_2 = PI;
 
	for(int it = 0; it < ITERATIONS; ++it){
		ldd mid_y = (lo + hi) / 2;
		ldd x1 = get_x(mid_y, alpha_1, theta_1);
		ldd x2 = L - get_x(mid_y, alpha_2, theta_2);
		if(x1 < x2){
			hi = mid_y;
		}else{
			lo = mid_y;
		}
 
	}
 
	return (A(PI, alpha_1) + A(PI, alpha_2)) - (A(theta_1, alpha_1) + A(theta_2, alpha_2));
}
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<Point> v(n);
for(auto& p:v)  cin>>p;
if(n == 4){
    int MY = max({v[0].y, v[1].y, v[2].y, v[3].y});
    int my = min({v[0].y, v[1].y, v[2].y, v[3].y});
    int MX = max({v[0].x, v[1].x, v[2].x, v[3].x});
    int mx = min({v[0].x, v[1].x, v[2].x, v[3].x});
    if(MY - my == 1 || MX - mx == 1){
        cout << fixed << setprecision(PRECISION) << 1.0 * (MY - my) * (MX - mx) << endl;
        exit(0);
    }
}
double ans=0.0;
for(int i=0;i<n;i++){
    ans+=getarea(v[(i-1+n)%n],v[i],v[(i+1)%n]);
}
for(int i=0;i<n;i++){
    Point a=v[(i-1+n)%n],b=v[i],c=v[(i+1)%n],d=v[(i+2)%n];
    if(norm(c-b)<3){
        ans-=find_overlap_area(getalpha(a,b,c),getalpha(b,c,d),sqrt(norm(c-b)));
    }
}
cout<<fixed<<setprecision(PRECISION)<<ans;
return 0;
}
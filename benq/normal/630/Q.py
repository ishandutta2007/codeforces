import math

a,b,c=map(float,input().split())
ans=0.0
ans += float(math.pow(a,3)*math.sqrt(2)/12);
ans += float(math.pow(b,3)*math.sqrt(2)/6);
ans += float(5*math.pow(c,3)*math.tan(math.radians(54))*math.sqrt(1-1/(4*math.cos(math.radians(54))*math.cos(math.radians(54))))/12);
print("%.20f" % ans)
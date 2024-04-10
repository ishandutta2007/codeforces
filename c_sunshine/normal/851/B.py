ax,ay,bx,by,cx,cy=map(int,input().split())
if (bx-ax)*(cy-ay)-(cx-ax)*(by-ay)==0:
    print("No")
    exit()
def chk(x1,y1,x2,y2):
    return x1*x1+y1*y1==x2*x2+y2*y2
if chk(ax-bx,ay-by,cx-bx,cy-by):
    print("Yes")
else:
    print("No")
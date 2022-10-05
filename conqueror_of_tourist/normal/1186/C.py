a = list(map(int,list(input())))
b = list(map(int,list(input())))

val = sum(b)%2
ind = 0
start = sum(a[:len(b)])

out = (val+start+1)%2
while ind < len(a)-len(b):
    start += (a[ind+len(b)]-a[ind])
    out += (val+start+1)%2
    ind += 1

print(out)
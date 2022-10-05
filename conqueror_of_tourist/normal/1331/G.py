l = []
for i in range(11):
    l = [int(input())] + l

for i in range(11):
    v = l[i]
    out = 5*v**3+abs(v)**.5
    if out <= 400:
        print("f({0}) = {1:.2f}".format(v,out))
    else:
        print("f({0}) = MAGNA NIMIS!".format(v,out))
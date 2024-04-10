for s in[*open(0)][2::2]:a=-1,*map(int,s.split());print(sum(i+j==x*a[j]for
i,x in enumerate(a)for j in range(-i%x,i,x)))
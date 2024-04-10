st1 = input()
st2 = input()

if st1.lower() == st2.lower():
	print(0)
elif st1.lower() < st2.lower():
	print(-1)
else:
	print(1)
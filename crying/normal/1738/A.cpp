__asm__(R"(
	.file	"E.cpp"
	.text
	.def	_ZSt9__reverseIPiEvT_S1_St26random_access_iterator_tag.isra.3;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt9__reverseIPiEvT_S1_St26random_access_iterator_tag.isra.3
_ZSt9__reverseIPiEvT_S1_St26random_access_iterator_tag.isra.3:
.LFB5336:
	.seh_endprologue
	cmpq	%rdx, %rcx
	leaq	-4(%rdx), %rax
	jne	.L6
	ret
.L6:
	cmpq	%rax, %rcx
	jae	.L8
	movl	(%rcx), %edx
	movl	(%rax), %r8d
	addq	$4, %rcx
	subq	$4, %rax
	movl	%r8d, -4(%rcx)
	movl	%edx, 4(%rax)
	jmp	.L6
.L8:
	ret
	.seh_endproc
	.def	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.8;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.8
_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.8:
.LFB5341:
	.seh_endprologue
	movl	(%rcx), %eax
.L10:
	movl	-4(%rcx), %edx
	cmpl	%edx, %eax
	jge	.L12
	movl	%edx, (%rcx)
	subq	$4, %rcx
	jmp	.L10
.L12:
	movl	%eax, (%rcx)
	ret
	.seh_endproc
	.def	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.10;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.10
_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.10:
.LFB5343:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$4, %r12d
	cmpq	%rdx, %rcx
	movq	%rcx, %rsi
	movq	%rdx, %rdi
	leaq	4(%rcx), %rbx
	je	.L13
.L24:
	cmpq	%rdi, %rbx
	je	.L13
	movl	(%rbx), %ebp
	cmpl	(%rsi), %ebp
	jge	.L16
	movq	%rbx, %r8
	subq	%rsi, %r8
	movq	%r8, %rax
	shrq	$2, %rax
	je	.L17
	movq	%r12, %rcx
	movq	%rsi, %rdx
	subq	%r8, %rcx
	addq	%rbx, %rcx
	call	memmove
.L17:
	movl	%ebp, (%rsi)
	jmp	.L18
.L16:
	movq	%rbx, %rcx
	call	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.8
.L18:
	addq	$4, %rbx
	jmp	.L24
.L13:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.seh_endproc
	.section	.text$_Z4Readv,"x"
	.linkonce discard
	.globl	_Z4Readv
	.def	_Z4Readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Readv
_Z4Readv:
.LFB4994:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$1, %esi
	orl	$-1, %edi
.L26:
	call	getchar
	leal	-48(%rax), %edx
	movb	%al, %bl
	cmpb	$9, %dl
	jbe	.L36
	cmpb	$45, %al
	cmove	%edi, %esi
	jmp	.L26
.L36:
	xorl	$48, %ebx
	movsbl	%bl, %ebx
.L33:
	call	getchar
	leal	-48(%rax), %edx
	cmpb	$9, %dl
	ja	.L37
	leal	(%rbx,%rbx), %edx
	xorl	$48, %eax
	leal	(%rdx,%rbx,8), %edx
	movsbl	%al, %ebx
	addl	%edx, %ebx
	jmp	.L33
.L37:
	movl	%ebx, %eax
	imull	%esi, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_Z5printx,"x"
	.linkonce discard
	.globl	_Z5printx
	.def	_Z5printx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5printx
_Z5printx:
.LFB4995:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	cmpq	$9, %rcx
	movq	%rcx, %rbx
	jle	.L39
	movq	%rbx, %rax
	movl	$10, %ecx
	cqto
	idivq	%rcx
	movq	%rax, %rcx
	call	_Z5printx
.L39:
	movq	%rbx, %rax
	movl	$10, %ecx
	cqto
	idivq	%rcx
	leal	48(%rdx), %ecx
	addq	$32, %rsp
	popq	%rbx
	jmp	putchar
	.seh_endproc
	.section	.text$_Z5Printxc,"x"
	.linkonce discard
	.globl	_Z5Printxc
	.def	_Z5Printxc;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5Printxc
_Z5Printxc:
.LFB4996:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	testq	%rcx, %rcx
	movq	%rcx, %rbx
	movl	%edx, %esi
	jns	.L41
	movl	$45, %ecx
	negq	%rbx
	call	putchar
.L41:
	movq	%rbx, %rcx
	call	_Z5printx
	movsbl	%sil, %ecx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	jmp	putchar
	.seh_endproc
	.section	.text$_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_,"x"
	.linkonce discard
	.globl	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	.def	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_:
.LFB5326:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	movl	$2, %r10d
	leaq	-1(%r8), %rax
	movq	%rdx, %r11
	cqto
	idivq	%r10
	movq	%r11, %r10
.L44:
	cmpq	%rax, %r10
	jge	.L54
	leaq	2(%r10,%r10), %rbx
	movl	-4(%rcx,%rbx,4), %esi
	cmpl	%esi, (%rcx,%rbx,4)
	leaq	-1(%rbx), %rdx
	cmovge	%rbx, %rdx
	movl	(%rcx,%rdx,4), %ebx
	movl	%ebx, (%rcx,%r10,4)
	movq	%rdx, %r10
	jmp	.L44
.L54:
	testb	$1, %r8b
	jne	.L47
	leaq	-2(%r8), %rax
	movl	$2, %ebx
	cqto
	idivq	%rbx
	cmpq	%rax, %r10
	jne	.L47
	leaq	2(%r10,%r10), %rax
	movl	-4(%rcx,%rax,4), %edx
	movl	%edx, (%rcx,%r10,4)
	leaq	-1(%rax), %r10
.L47:
	leaq	-1(%r10), %rax
	movl	$2, %ebx
	cqto
	idivq	%rbx
.L53:
	cmpq	%r11, %r10
	movq	%rax, %r8
	jg	.L49
.L50:
	movl	%r9d, (%rcx,%r10,4)
	popq	%rbx
	popq	%rsi
	ret
.L49:
	movl	(%rcx,%rax,4), %eax
	cmpl	%r9d, %eax
	jge	.L50
	movl	%eax, (%rcx,%r10,4)
	leaq	-1(%r8), %rax
	movq	%r8, %r10
	cqto
	idivq	%rbx
	jmp	.L53
	.seh_endproc
	.text
	.def	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.19;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.19
_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.19:
.LFB5352:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rcx, %rbx
	movq	%rdx, %rsi
	movq	%r8, %rbp
.L56:
	movq	%rsi, %rax
	subq	%rbx, %rax
	cmpq	$67, %rax
	jle	.L55
	testq	%rbp, %rbp
	jne	.L57
	sarq	$2, %rax
	leaq	-2(%rax), %rbp
	movq	%rax, %rdi
	sarq	%rbp
.L60:
	movl	(%rbx,%rbp,4), %r9d
	movb	$0, 32(%rsp)
	movq	%rdi, %r8
	movq	%rbp, %rdx
	movq	%rbx, %rcx
	call	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	testq	%rbp, %rbp
	je	.L59
	decq	%rbp
	jmp	.L60
.L59:
	movq	%rsi, %rax
	subq	%rbx, %rax
	cmpq	$7, %rax
	jle	.L55
	subq	$4, %rsi
	movl	(%rbx), %eax
	movl	(%rsi), %r9d
	movq	%rsi, %r8
	xorl	%edx, %edx
	movq	%rbx, %rcx
	subq	%rbx, %r8
	movl	%eax, (%rsi)
	sarq	$2, %r8
	movb	$0, 32(%rsp)
	call	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	jmp	.L59
.L57:
	sarq	$3, %rax
	movl	4(%rbx), %r9d
	decq	%rbp
	leaq	(%rbx,%rax,4), %r8
	leaq	4(%rbx), %rdi
	movl	(%rbx), %eax
	movl	-4(%rsi), %edx
	movl	(%r8), %ecx
	cmpl	%ecx, %r9d
	jge	.L62
	cmpl	%edx, %ecx
	jl	.L68
	cmpl	%edx, %r9d
	jge	.L65
	jmp	.L78
.L62:
	cmpl	%edx, %r9d
	jge	.L67
.L65:
	movl	%r9d, (%rbx)
	movl	%eax, 4(%rbx)
.L64:
	movq	%rsi, %r8
	jmp	.L66
.L67:
	cmpl	%edx, %ecx
	jge	.L68
.L78:
	movl	%edx, (%rbx)
	movl	%eax, -4(%rsi)
	jmp	.L64
.L68:
	movl	%ecx, (%rbx)
	movl	%eax, (%r8)
	jmp	.L64
.L80:
	cmpq	%rax, %rdi
	movq	%rax, %r8
	jae	.L77
	movl	%ecx, (%rdi)
	movl	%edx, (%rax)
	addq	$4, %rdi
.L66:
	movl	(%rbx), %r9d
.L69:
	movl	(%rdi), %edx
	cmpl	%r9d, %edx
	jge	.L79
	addq	$4, %rdi
	jmp	.L69
.L79:
	leaq	-4(%r8), %rax
.L71:
	movl	(%rax), %ecx
	cmpl	%ecx, %r9d
	jge	.L80
	subq	$4, %rax
	jmp	.L71
.L77:
	movq	%rsi, %rdx
	movq	%rbp, %r8
	movq	%rdi, %rcx
	call	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.19
	movq	%rdi, %rsi
	jmp	.L56
.L55:
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.def	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.20;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.20
_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.20:
.LFB5353:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	cmpq	%rdx, %rcx
	je	.L81
	movq	%rdx, %rdi
	movl	$63, %r8d
	movq	%rdx, %rsi
	subq	%rcx, %rdi
	movq	%rcx, %rbx
	movq	%rdi, %rax
	sarq	$2, %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	cltq
	subq	%rax, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.19
	cmpq	$67, %rdi
	jle	.L84
	leaq	64(%rbx), %rdi
	movq	%rbx, %rcx
	movq	%rdi, %rdx
	call	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.10
.L85:
	cmpq	%rsi, %rdi
	je	.L81
	movq	%rdi, %rcx
	addq	$4, %rdi
	call	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.8
	jmp	.L85
.L84:
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	jmp	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.10
.L81:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_Z5Solvev,"x"
	.linkonce discard
	.globl	_Z5Solvev
	.def	_Z5Solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5Solvev
_Z5Solvev:
.LFB4997:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	xorl	%ebx, %ebx
	call	_Z4Readv
	movl	$0, 4+cnt(%rip)
	movl	%eax, n(%rip)
	movl	$0, cnt(%rip)
	movq	$0, s2(%rip)
	movq	$0, s1(%rip)
.L89:
	leal	1(%rbx), %eax
	incq	%rbx
	cmpl	n(%rip), %eax
	jg	.L109
	call	_Z4Readv
	leaq	a(%rip), %rdx
	movl	%eax, (%rdx,%rbx,4)
	jmp	.L89
.L109:
	xorl	%ebx, %ebx
.L91:
	movl	n(%rip), %r8d
	leal	1(%rbx), %eax
	incq	%rbx
	cmpl	%r8d, %eax
	jg	.L110
	call	_Z4Readv
	leaq	b(%rip), %rdx
	movl	%eax, (%rdx,%rbx,4)
	cltq
	addq	%rax, s1(%rip)
	addq	%rax, s2(%rip)
	jmp	.L91
.L110:
	xorl	%edx, %edx
.L93:
	incq	%rdx
	leaq	val(%rip), %rbx
	cmpl	%edx, %r8d
	jl	.L111
	leaq	a(%rip), %rax
	leaq	cnt(%rip), %r9
	movslq	(%rax,%rdx,4), %rcx
	movl	(%r9,%rcx,4), %eax
	incl	%eax
	movl	%eax, (%r9,%rcx,4)
	cltq
	imulq	$100005, %rcx, %rcx
	addq	%rcx, %rax
	leaq	b(%rip), %rcx
	movl	(%rcx,%rdx,4), %ecx
	movl	%ecx, (%rbx,%rax,4)
	jmp	.L93
.L111:
	movslq	cnt(%rip), %rax
	leaq	4+val(%rip), %rcx
	leaq	400020+val(%rip), %rsi
	leaq	4(%rbx,%rax,4), %rdx
	call	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.20
	movslq	4+cnt(%rip), %rax
	leaq	400024+val(%rip), %rcx
	leaq	4(%rsi,%rax,4), %rdx
	call	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_.isra.20
	movslq	cnt(%rip), %rax
	leaq	4+val(%rip), %rcx
	leaq	4(%rbx,%rax,4), %rdx
	call	_ZSt9__reverseIPiEvT_S1_St26random_access_iterator_tag.isra.3
	movslq	4+cnt(%rip), %rax
	leaq	400024+val(%rip), %rcx
	leaq	4(%rsi,%rax,4), %rdx
	call	_ZSt9__reverseIPiEvT_S1_St26random_access_iterator_tag.isra.3
	movl	cnt(%rip), %ecx
	movl	4+cnt(%rip), %r8d
	movq	%rbx, %r9
	movq	s1(%rip), %rax
	movl	$1, %edx
.L95:
	cmpl	%ecx, %edx
	jg	.L112
	cmpl	%r8d, %edx
	jg	.L96
	movslq	4(%r9), %r10
	addq	%r10, %rax
.L96:
	incl	%edx
	addq	$4, %r9
	jmp	.L95
.L112:
	leaq	val(%rip), %r9
	movl	$1, %edx
.L98:
	cmpl	%r8d, %edx
	jg	.L113
	cmpl	%ecx, %edx
	jge	.L99
	movslq	400024(%r9), %r10
	addq	%r10, %rax
.L99:
	incl	%edx
	addq	$4, %r9
	jmp	.L98
.L113:
	movq	%rax, s1(%rip)
	movq	s2(%rip), %rax
	leaq	val(%rip), %r9
	movl	$1, %edx
.L101:
	cmpl	%r8d, %edx
	jg	.L114
	cmpl	%ecx, %edx
	jg	.L102
	movslq	400024(%r9), %r10
	addq	%r10, %rax
.L102:
	incl	%edx
	addq	$4, %r9
	jmp	.L101
.L114:
	movl	$1, %edx
.L104:
	cmpl	%ecx, %edx
	jg	.L115
	cmpl	%r8d, %edx
	jge	.L105
	movslq	4(%rbx), %r9
	addq	%r9, %rax
.L105:
	incl	%edx
	addq	$4, %rbx
	jmp	.L104
.L115:
	movq	s1(%rip), %rcx
	movq	%rax, s2(%rip)
	movl	$10, %edx
	cmpq	%rax, %rcx
	jg	.L108
	movq	%rax, %rcx
.L108:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	jmp	_Z5Printxc
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4998:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	call	_Z4Readv
	movl	%eax, T(%rip)
.L117:
	cmpl	$0, T(%rip)
	je	.L119
	call	_Z5Solvev
	decl	T(%rip)
	jmp	.L117
.L119:
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.globl	T
	.bss
	.align 4
T:
	.space 4
	.globl	s2
	.align 8
s2:
	.space 8
	.globl	s1
	.align 8
s1:
	.space 8
	.globl	b
	.align 64
b:
	.space 400020
	.globl	a
	.align 64
a:
	.space 400020
	.globl	cnt
	.align 8
cnt:
	.space 8
	.globl	val
	.align 64
val:
	.space 800040
	.globl	n
	.align 4
n:
	.space 4
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef

)");